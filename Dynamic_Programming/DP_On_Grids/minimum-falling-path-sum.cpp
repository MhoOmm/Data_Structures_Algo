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