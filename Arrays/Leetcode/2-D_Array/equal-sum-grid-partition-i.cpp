class Solution {
public:
    typedef long long ll;
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m  = grid.size();
        int n  = grid[0].size();

        vector<ll>hortSum(m,0);
        vector<ll>vertSum(n,0);
        ll totHortSum = 0;
        ll totVertSum = 0;

        ll total = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                total += grid[i][j];
                //row = i
                hortSum[i] += grid[i][j];
                //col = j
                vertSum[j] += grid[i][j];
            }
        }
        ll upper = 0;
        for(int i=0;i<m-1;i++)
        {
            upper += hortSum[i];
            if(upper == total-upper){
                return true;
            }
        }
        //Vertical split
        ll left = 0;
        for(int j = 0; j < n-1; j++) {
            left += vertSum[j];
            if(left == total - left) {
                return true;
            }
        }

        return false;
    }
};