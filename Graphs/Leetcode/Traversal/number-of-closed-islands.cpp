class Solution {
public:
    int n,m;
    bool dfs(int i,int j,vector<vector<int>>& grid)
    {
        if(i<0 || i>=n || j<0 || j>=m)
        {
            return false;
        }
        if(grid[i][j]==1)
        {
            return true; // iss direction mein island mil gaya
        }

        grid[i][j]  =1; // isko bana diya;
        int up = dfs(i-1,j,grid);
        int down = dfs(i+1,j,grid);
        int right = dfs(i,j+1,grid);
        int left = dfs(i,j-1,grid);

        return up && down && right && left;
    }
    int closedIsland(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    if(dfs(i,j,grid))
                    {
                        count++;
                    }
                }
            }
        }

        return count;
    }
};