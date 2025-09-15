class Solution {
    public:
        int t[201][201];
        int m,n;
        int solve(int i,int j,vector<vector<int>>& grid)
        {
            if(i==m-1&&j==n-1)
            {
                return grid[i][j];
            }
            if (i >= m || j >= n) {
                return INT_MAX;  // Invalid path
            }
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
    
            int right=solve(i,j+1,grid);
            int down=solve(i+1,j,grid);
    
            return t[i][j]=grid[i][j]+min(right,down);
        }
        int minPathSum(vector<vector<int>>& grid) {
    
            m=grid.size();
            n=grid[0].size();
    
            memset(t,-1,sizeof(t));
    
            return solve(0,0,grid);
        }
    };


    //bottom up 

    class Solution {
        public:
            int minPathSum(vector<vector<int>>& grid) {
                int m=grid.size();
                int n=grid[0].size();
                vector<vector<int>>t(m,vector<int>(n));
        
                t[0][0]=grid[0][0];
                for(int i=1;i<m;i++)
                {
                    t[i][0]=grid[i][0]+t[i-1][0];
                }
                 for(int j=1;j<n;j++)
                {
                    t[0][j]=grid[0][j]+t[0][j-1];
                }
        
        
                for(int i=1;i<m;i++)
                {
                    for(int j=1;j<n;j++)
                    {
                        t[i][j]=grid[i][j] +min(t[i][j-1],t[i-1][j]);
                    }
                }
        
                return t[m-1][n-1];
        
            }
        };