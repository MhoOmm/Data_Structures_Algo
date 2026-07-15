class Solution {
public:
    int n;
    int t[201][201];
    int solve(vector<vector<int>>&matrix,int i,int j)
    {
        if(i>=n || j>=n || i<0 || j<0)
        {
            return INT_MAX;
        }
        if(i==n-1)
        {
            return matrix[i][j];
        }
        if(t[i][j]!=INT_MAX)
        {
            return t[i][j];
        }
        int ans = INT_MAX;

        for(int col=0;col<n;col++)
        {
            if(col!=j)
            {
                int nextEle = solve(matrix,i+1,col);
                if(nextEle!=INT_MAX)
                {
                    ans = min(ans,matrix[i][j] + nextEle);
                }
            }
        }
        return t[i][j] = ans;
    }
    int minFallingPathSum(vector<vector<int>>& grid) {
        n = grid.size();
        int minSum = INT_MAX;
        for(int i=0;i<201;i++)
        {
            for(int j=0;j<201;j++)
            {
                t[i][j] = INT_MAX;
            }
        }
        for(int j=0;j<n;j++)
        {
            int sum = solve(grid,0,j);
            minSum = min(sum,minSum);
        }

        return minSum;
    }
};