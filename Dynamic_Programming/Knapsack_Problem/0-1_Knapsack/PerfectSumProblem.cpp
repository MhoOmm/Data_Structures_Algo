class Solution {
public:
    int mod = 1e9 + 7; 

    int perfectSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));

        for (int i = 0; i <= n; i++) {
            t[i][0] = 1;
        }

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] > j) {
                    t[i][j] = t[i - 1][j];
                } else {
                    t[i][j] = (t[i - 1][j] + t[i - 1][j - arr[i - 1]]) % mod;
                }
            }
        }

        return t[n][target];
    }
};
