
// https://leetcode.com/problems/number-of-ways-to-paint-n-3-grid/description/
class Solution {
public:
    vector<string> states;
    int mod = 1e9 + 7;
    vector<vector<int>> dp;

    void generate(int i, char prev, string curr) {
        if (i == 3) {
            states.push_back(curr);
            return;
        }
        for (char ch : {'R', 'G', 'Y'}) {
            if (ch == prev) continue;
            generate(i + 1, ch, curr + ch);
        }
    }

    int solve(int prev, int remcol) {
        if (remcol == 0) return 1;
        if (dp[prev][remcol] != -1) return dp[prev][remcol];

        int ways = 0;
        string prevstr = states[prev];

        for (int i = 0; i < states.size(); i++) {
            string currstr = states[i];
            if (currstr == prevstr) continue;
            bool valid = true;
            for (int j = 0; j < 3; j++) {
                if (currstr[j] == prevstr[j]) {
                    valid = false;
                    break;
                }
            }
            if (valid) {
                ways = (ways + solve(i, remcol - 1)) % mod;
            }
        }

        return dp[prev][remcol] = ways;
    }

    int numOfWays(int n) {
        generate(0, '#', "");
        int totalstates = states.size();
        dp.assign(totalstates, vector<int>(n, -1));
        
        int result = 0;
        for (int i = 0; i < totalstates; i++) {
            result = (result + solve(i, n - 1)) % mod;
        }
        return result;
    }
};