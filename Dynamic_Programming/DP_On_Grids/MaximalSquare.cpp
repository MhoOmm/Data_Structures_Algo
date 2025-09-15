
//recurr+memo

class Solution {
    public:
    
        int m,n;
    
        int t[301][301];
    
        int solve(int i,int j,vector<vector<char>>& matrix)
        {
            if(i>=m||j>=n|| matrix[i][j]=='0')
            {
                return 0;
            }
    
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            int right,diag,down;
            right=solve(i,j+1,matrix);
            diag=solve(i+1,j+1,matrix);
            down=solve(i+1,j,matrix);
            return t[i][j]=1+min({right,down,diag});
        }
        int maximalSquare(vector<vector<char>>& matrix) {
    
            m=matrix.size();
            n=matrix[0].size();
    
            memset(t,-1,sizeof(t));
    
            int maxval=0;
    
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    maxval=max(maxval,solve(i,j,matrix));
                }
            }
    
            return maxval*maxval;
            
        }
    };

// bottom up approach
class Solution {
    public:
        int maximalSquare(vector<vector<char>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            vector<vector<int>> t(m, vector<int>(n, 0));
            int maxval = 0;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == '1') {
                        if (i == 0 || j == 0) {
                            t[i][j] = 1;
                        } else {
                            t[i][j] = 1 + min({t[i - 1][j], t[i - 1][j - 1], t[i][j - 1]});
                        }
                        maxval = max(maxval, t[i][j]);
                    }
                }
            }
    
            return maxval * maxval;
        }
    };