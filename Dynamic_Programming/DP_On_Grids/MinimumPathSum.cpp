// recur +memo 

class Solution {
    public:
        int MFS(vector<vector<int>>& A, int row, int col, vector<vector<int>>& t) {
            if(row == A.size()-1)
                return A[row][col];
            if(t[row][col] != -1)
                return t[row][col];
            
            int minSum = INT_MAX;
            
            for(int shift = -1; shift<=1; shift++) {
                if(col + shift >=0 && col+shift < A[row].size()) {
                    minSum = min(minSum, A[row][col] + MFS(A, row+1, col+shift, t));
                }
            }
            
            return t[row][col] = minSum;
        }
        int minFallingPathSum(vector<vector<int>>& A) {
            int m = A.size(); //row
            int n = m; //column
            vector<vector<int>> t(m, vector<int>(n, -1));
            int result = INT_MAX;
            for(int col = 0; col<n; col++) {
                result = min(result, MFS(A, 0, col, t));
            }
            return result;
        }
    };


    // bottom up 

    class Solution {
        public:
            int minFallingPathSum(vector<vector<int>>& matrix) {
        
                int n=matrix.size();
        
                vector<vector<int>>t(n,vector<int>(n));
        
                for(int j=0;j<n;j++)
                {
                  t[0][j]=matrix[0][j];  
                }
        
                for(int i=1;i<n;i++)
                {
                    for(int j=0;j<n;j++)
                    {
                        t[i][j]=matrix[i][j]+min({t[i-1][j],t[i-1][max(0,j-1)],t[i-1][min(n-1,j+1)]});
                    }
                }
        
                int result=INT_MAX;
        
                for(int col=0;col<n;col++)
                {
                    result=min(result,t[n-1][col]);
                }
        
                return result;
                
            }
        };