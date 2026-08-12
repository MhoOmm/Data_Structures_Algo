class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        int n = grid[0].size();

        vector<long long> top(n);
        vector<long long> bottom(n);

        top[0] = grid[0][0];
        bottom[0] = grid[1][0];

        for (int j = 1; j < n; j++) {
            top[j] = top[j - 1] + grid[0][j];
            bottom[j] = bottom[j - 1] + grid[1][j];
        }

        long long totalTop = top[n - 1];

        long long ans = LLONG_MAX;

        for (int j = 0; j < n; j++) {
            long long topSuffix = totalTop - top[j];

            long long bottomPrefix = (j == 0)
                                    ? 0
                                    : bottom[j - 1];

            ans = min(ans, max(topSuffix, bottomPrefix));
        }

        return ans;
    }
};