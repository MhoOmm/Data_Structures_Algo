class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    bool dfs(int i,int j,vector<vector<int>>&grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j] == 1)
        {
            return false;
        }
        if(i==n-1)
        {
            return true; //destination achieved
        }
        grid[i][j] = 1;
        for(auto &dir:directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            if(dfs(ni,nj,grid))return true;
        }
        return false;
    }
    bool canGo(int mid,vector<vector<int>>&cells)
    {
        vector<vector<int>>grid(n,vector<int>(m,0));
        for(int i=0;i<mid;i++)
        {
            int a = cells[i][0] - 1; // zero based indexing
            int b = cells[i][1] - 1;
            grid[a][b] = 1;
        }

        for(int j=0;j<m;j++)
        {
            if (grid[0][j] == 0 && dfs(0, j,grid)) {
                return true;
            }
        }
        return false;
    }
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) 
    {
        n = row;
        m = col;
        int l = 0;
        int r =  cells.size();
        int result = INT_MAX;
        while(l<=r)
        {
            int mid = l + (r-l)/2;
            if(canGo(mid,cells))
            {
                result = mid;
                l = mid+1;
            }else{
                r = mid-1;
            }
        } 

        return result; 
    }
};