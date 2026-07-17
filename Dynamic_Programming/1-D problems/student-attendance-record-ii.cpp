class Solution {
public:
    int mod = 1e9+7;
    int dp[100001][2][3];
    int solve(int i,int abs,int late,int n){
        if(i==n)
        {
            return 1; // successfull 
        }
        int ans = 0;
        if (dp[i][abs][late] != -1)return dp[i][abs][late];
        // is absent
        if (abs == 0) {
            ans = (ans + solve(i+1, 1, 0, n)) % mod;
        }
        // is late
        if(late<2){
            ans= (ans+ solve(i+1,abs,late+1,n))%mod;
        }
        // is present
        ans = (ans+solve(i+1,abs,0,n))%mod;

        return dp[i][abs][late] = ans;
    }
    int checkRecord(int n) {
        memset(dp, -1, sizeof(dp));
        return solve(0,0,0, n);
    }
};