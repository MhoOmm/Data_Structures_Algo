//code correct but giving tle as tc is o(n^n *n)

//memoization ka tc: o(n^3)
class Solution {
    public:
        int t[201][201];
        int n;
        int solve(int col,int row,vector<vector<int>>& grid)
        {
            if(row==n-1)
            {
                return grid[row][col];
            }
            if(t[row][col]!=-1)
            {
                return t[row][col];
            }
    
            int ans=INT_MAX;
            for(int nextcol=0;nextcol<n;nextcol++)
            {
                if( nextcol != col)
                {
                    ans=min(ans,solve(nextcol,row+1,grid));
                }
            }
    
            return t[row][col]=grid[row][col]+ans;
    
        }
        int minFallingPathSum(vector<vector<int>>& grid) {
    
            n=grid.size();
            int result=INT_MAX;
            memset(t,-1,sizeof(t));
            for(int col=0;col<n;col++)
            {
                result=min(result,solve(col,0,grid));
            }
            return result; 
        }
    };

    // bottom up approach

    class Solution {
        public:
            int minFallingPathSum(vector<vector<int>>& grid) {
                int n=grid.size();
        
                vector<vector<int>>t(n,vector<int>(n));
                //filling the bottom row of the dp matrix
        
                for(int i=0;i<n;i++)
                {
                    t[n-1][i]=grid[n-1][i];
                }
                for(int row=n-2;row>=0;row--)
                {
                    for(int col=0;col<n;col++)
                    {
                        int ans=INT_MAX;
                        for(int nc=0;nc<n;nc++)
                        {
                            if(nc!=col)
                            {
                                ans=min(ans,t[row+1][nc]);
                            }
                        }
                        t[row][col]=grid[row][col]+ans;
                    }
                
                }
        
                int result=INT_MAX;
                for(int j=0;j<n;j++)
                {
                    result=min(result,t[0][j]);
                }
        
                return result; 
            }
        };

// APPROACH 3 TIME OPTIMISED O(N^2)

class Solution {
    public:
        int minFallingPathSum(vector<vector<int>>& grid) {
            int n=grid.size();
    
            vector<vector<int>>t(n,vector<int>(n));
            //filling the bottom row of the dp matrix
    
            int nextMin1Col=-1;
            int nextMin2Col=-1;
    
            for (int col = 0; col < n; col++) {
                t[n - 1][col] = grid[n - 1][col];
                
                if(nextMin1Col == -1 || t[n - 1][col] <= t[n-1][nextMin1Col]) {
                    nextMin2Col = nextMin1Col;
                    nextMin1Col = col;
                } else if(nextMin2Col == -1 || t[n - 1][col] <= t[n-1][nextMin2Col]) {
                    nextMin2Col = col;
                }
            }
    
            //mainprogram
    
            for(int row=n-2;row>=0;row--)
            {
                int min1Col = -1;
                int min2Col = -1;
                
                for (int col = 0; col < n; col++) {
                    
                    if(col != nextMin1Col) {
                        t[row][col] = grid[row][col] + t[row+1][nextMin1Col];
                    } else {
                        t[row][col] = grid[row][col] + t[row+1][nextMin2Col];
                    }
                    
                    if(min1Col == -1 || t[row][col] <= t[row][min1Col]) {
                        min2Col = min1Col;
                        min1Col = col;
                    } else if(min2Col == -1 || t[row][col] <= t[row][min2Col]) {
                        min2Col = col;
                    }
                }
                                
                nextMin1Col = min1Col;
                nextMin2Col = min2Col;
            
            }
    
            int result=INT_MAX;
            return t[0][nextMin1Col];
    
            return result; 
        }
    };

//Approach-4 
//T.C : O(N^2)
//S.C : O(1)
class Solution {
    public:
        int n;
        
        int minFallingPathSum(vector<vector<int>>& grid) {
            int n = grid.size();
    
            int nextMin1Col = -1;
            int nextMin2Col = -1;
            
            int nextMin1Val = -1;
            int nextMin2Val = -1;
            
            for (int col = 0; col < n; col++) {
    
                if(nextMin1Col == -1 || grid[n - 1][col] <= nextMin1Val) {
                    nextMin2Col = nextMin1Col;
                    nextMin2Val = nextMin1Val;
                    
                    nextMin1Col = col;
                    nextMin1Val = grid[n-1][col];
                    
                } else if(nextMin2Col == -1 || grid[n - 1][col] <= nextMin2Val) {
                    nextMin2Col = col;
                    nextMin2Val = grid[n-1][col];
                }
            }
    
            for (int row = n - 2; row >= 0; row--) {
                
                int min1Col = -1;
                int min2Col = -1;
                
                int min1Val = -1;
                int min2Val = -1;
                
                for (int col = 0; col < n; col++) {
                    
                    int ans;
                    if(col != nextMin1Col) {
                        ans = grid[row][col] + nextMin1Val;
                    } else {
                        ans = grid[row][col] + nextMin2Val;
                    }
                    
                    if(min1Col == -1 || ans <= min1Val) {
                        min2Col = min1Col;
                        min2Val = min1Val;
                        
                        min1Col = col;
                        min1Val = ans;
                    } else if(min2Col == -1 || ans <= min2Val) {
                        min2Col = col;
                        min2Val = ans;
                    }
                }
                                
                nextMin1Col = min1Col;
                nextMin1Val = min1Val;
                
                nextMin2Col = min2Col;
                nextMin2Val = min2Val;
                    
            }
    
            // Return the minimum from the first row
            return nextMin1Val;
        }
    };
