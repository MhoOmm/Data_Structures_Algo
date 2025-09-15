
// recurr+ memoization

class Solution {
    public:
        int m, n;
        int t[301][301];
        int solve(int i, int j, vector<vector<int>>& matrix) {
            if (i >= m || j >= n || matrix[i][j] == 0) {
                return 0;
            }
    
            if (t[i][j] != -1) {
                return t[i][j];
            }
    
            int right = solve(i, j + 1, matrix);
            int down = solve(i + 1, j, matrix);
            int diag = solve(i + 1, j + 1, matrix);
            return t[i][j] = 1 + min({right, down, diag});
        }
    
        int countSquares(vector<vector<int>>& matrix) {
            m = matrix.size();
            n = matrix[0].size();
    
            memset(t, -1, sizeof(t));
    
            int totalSquares = 0;
    
            for (int i = 0; i < m; ++i) {
                for (int j = 0; j < n; ++j) {
                    totalSquares += solve(i, j, matrix);
                }
            }
    
            return totalSquares;
        }
    };

//bottom up 


class Solution {
    public:
        int countSquares(vector<vector<int>>& matrix) {
            int m = matrix.size();
            int n = matrix[0].size();
            
            vector<vector<int>> t(m, vector<int>(n, 0));
            int maxval = 0;
    
            for (int i = 0; i < m; i++) {
                for (int j = 0; j < n; j++) {
                    if (matrix[i][j] == 1) {
                        if (i == 0 || j == 0) {
                            t[i][j] = 1;
                        } else {
                            t[i][j] = 1 + min({t[i - 1][j], t[i - 1][j - 1], t[i][j - 1]});
                        }
                        maxval += t[i][j];
                    }
                }
            }
    
            return maxval;
        }
    };
