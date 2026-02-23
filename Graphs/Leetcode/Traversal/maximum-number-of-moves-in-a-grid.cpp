class Solution {
public:
    vector<vector<int>>directions={{1,1},{-1,+1},{0,1}};
    int n,m;
    int t[1001][1001];
    int dfs(int i,int j,vector<vector<int>>& grid)
    {
        int maxcount =0;
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        for(auto &dir:directions)
        {
            int ni = i+dir[0];
            int nj = j+dir[1];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]>grid[i][j])
            {
                maxcount = max(maxcount,1+dfs(ni,nj,grid));
            }
        }
        return t[i][j] = maxcount;
    }
    int maxMoves(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        memset(t,-1,sizeof(t));
        int maxCount =0;
        for(int i=0;i<n;i++)
        {
            maxCount = max(maxCount,dfs(i,0,grid));
        }
        return maxCount;
    }
};