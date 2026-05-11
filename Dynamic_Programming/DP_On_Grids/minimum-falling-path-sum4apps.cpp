//memoization ka tc: o(n^2)
class Solution {
public:
    int n;
    int t[101][101];
    int solve(vector<vector<int>>&matrix,int i,int j)
    {
        if(i>=n || j>=n || i<0 || j<0)
        {
            return 1e9;
        }
        if(i==n-1)
        {
            return matrix[i][j];
        }
        if(t[i][j]!= INT_MAX)
        {
            return t[i][j];
        }
        // down
        int d = matrix[i][j] + solve(matrix,i+1,j);
        // down left
        int dl = matrix[i][j] + solve(matrix,i+1,j-1);
        // down right
        int dr = matrix[i][j] + solve(matrix,i+1,j+1);
        return t[i][j] = min({d,dl,dr});
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        n = matrix.size();
        int minSum = INT_MAX;
        for(int i=0;i<101;i++)
        {
            for(int j=0;j<101;j++)
            {
                t[i][j] = INT_MAX;
            }
        }
        for(int j=0;j<n;j++)
        {
            int sum = solve(matrix,0,j);
            minSum = min(sum,minSum);
        }

        return minSum;
    }
};

// bottom up approach

// bottom up approach
class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<vector<int>>t(n,vector<int>(n,INT_MAX));  

        // first row will have the matrix element
        for(int j=0;j<n;j++)
        {
            t[0][j] = matrix[0][j];
        }

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                int u =  t[i-1][j];
                int ul = (j>0)?t[i-1][j-1]:1e9;
                int ur = (j<n-1)?t[i-1][j+1]:1e9;
                t[i][j] = matrix[i][j] + min({u,ul,ur});
            }
        }

        // find the minimum from the last row;
        int result = INT_MAX;
        for(int j=0;j<n;j++)
        {
            result = min(result,t[n-1][j]);
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
