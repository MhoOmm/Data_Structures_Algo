class Solution {
    public:
        int m;
        int t[201][201];
    
        int solve(int i, int j, vector<vector<int>>& triangle) {
            if (j < 0 || j >= triangle[i].size()) return INT_MAX;
    
            if (i == m - 1) return triangle[i][j];
    
            if (t[i][j] != -1) return t[i][j];
    
            int res = INT_MAX;
    
            int dr = solve(i + 1, j + 1, triangle);
            if (dr != INT_MAX) res = min(res, dr);
    
            int down = solve(i + 1, j, triangle);
            if (down != INT_MAX) res = min(res, down);
    
            return t[i][j] = triangle[i][j] + res;
        }
    
    
        int minimumTotal(vector<vector<int>>& triangle) {
            m = triangle.size();
            memset(t, -1, sizeof(t));
            return solve(0, 0, triangle);
        }
    };

//bottom up approach 

class Solution {
    public:
        int minimumTotal(vector<vector<int>>& triangle) {
            
            int n=triangle.size();
    
            vector<vector<int >>t(n,vector<int>(n));
            for(int j=0;j<n ;j++)
            {
                t[n-1][j]=triangle[n-1][j];
            }
    
            for(int i=n-2;i>=0;i--)
            {
                for(int j = 0; j <= i; j++)
                {
                    int dr=triangle[i][j]+ t[i+1][j];
                    int dow=triangle[i][j]+t[i+1][j+1];
                    t[i][j]=min(dr,dow);
                }
            }
    
            return t[0][0];
    
        }
    };