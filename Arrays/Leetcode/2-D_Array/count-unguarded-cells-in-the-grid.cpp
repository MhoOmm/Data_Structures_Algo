class Solution {
public:
    void markWatch(int r,int c,vector<vector<int>>&grid)
    {
        //up
        for(int i=r-1;i>=0;i--)
        {
            if(grid[i][c] == 2 || grid[i][c] == 3) {
                break;
            }
            grid[i][c] = 1;
        }
        // down
        for(int i=r+1;i<grid.size();i++)
        {
            if(grid[i][c] == 2 || grid[i][c] == 3) {
                break;
            }
            grid[i][c] = 1;
        }

        // left
        for(int i =c-1;i>=0;i--)
        {
            if(grid[r][i] == 2 || grid[r][i] == 3)
            {
                break;
            }
            grid[r][i]=1;
        }
        // right
        for(int i =c+1;i<grid[0].size();i++)
        {
            if(grid[r][i] == 2 || grid[r][i] == 3)
            {
                break;
            }
            grid[r][i]=1;
        }


    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards, vector<vector<int>>& walls) {
        vector<vector<int>>grid(m,vector<int>(n,0));
        // define guards
        for(auto &vec:guards)
        {
            int i1 = vec[0];
            int i2 = vec[1];

            grid[i1][i2]=2;
        }
        // define walls
        for(auto &vec:walls)
        {
            int i1 = vec[0];
            int i2 = vec[1];

            grid[i1][i2]=3;
        }

        // start moving
        for(auto &guard:guards)
        {
           int g1 = guard[0];
           int g2 = guard[1];
           markWatch(g1,g2,grid);
        }

        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j =0;j<n;j++)
            {
                if(grid[i][j]==0)
                {
                    count++;
                }
            }
        }

        return count;
    }
};