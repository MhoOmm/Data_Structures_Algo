class Solution {
public:
    int countPartitions(vector<int>& arr, int d) {
        int mod = 1e9 + 7;
        int n = arr.size();
        int sum = accumulate(arr.begin(), arr.end(), 0);

       
        if ((sum + d) % 2 != 0 || sum < d) return 0;

        int target = (sum + d) / 2;

        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++) t[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (arr[i - 1] <= j)
                    t[i][j] = (t[i - 1][j] + t[i - 1][j - arr[i - 1]]) % mod;
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][target];
    }
};
