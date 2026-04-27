class Solution {
public:
    vector<vector<vector<int>>>direction={
        {},// compensation for zero
        {{0,1},{0,-1}},//1
        {{-1,0},{1,0}},// 2
        {{0,-1},{1,0}},// 3
        {{0,1},{1,0}},// 4
        {{0,-1},{-1,0}},// 5
        {{0,1},{-1,0}} //6
    
    };
    bool dfs(int i,int j,int m,int n,vector<vector<int>>& grid)
    {
        if(i==m-1 && j==n-1){
            return true;
        }

        if(i<0 || j<0 || i>=m || j>=n || grid[i][j]==0)
        {
            return false;
        }
        int temp = grid[i][j];
        grid[i][j] = 0;
        for(auto &dir:direction[temp])
        {
            int ni = i+dir[0];
            int nj = j+dir[1];
            if(ni<0 || nj<0 || ni>=m || nj>=n || grid[ni][nj]==0)continue;
            // checking backward equal or not
            for(auto val:direction[grid[ni][nj]])
            {
                if(ni+val[0]==i && nj+val[1]==j )
                {
                    if(dfs(ni,nj,m,n,grid))return true;
                }
            }
        }

        return false;
    }
    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        return dfs(0,0,m,n,grid);
    }
};