// Recursion + Memo
class Solution {
public:
    long mod = 1e9+7;
    int t[31][1001];
    int solve(int n,int k, int target)
    {
        if(target<0)return 0;

        if(n==0) return target==0;

        if(t[n][target]!=-1)
        {
            return t[n][target];
        }

        int ways = 0;

        for(int i=1;i<=k;i++)
        {
            ways= ways+solve(n-1,k,target-i);
            ways%=mod;
        }

        return t[n][target]=ways;
    }
    int numRollsToTarget(int n, int k, int target) {
        memset(t,-1,sizeof(t));
        return solve(n,k,target);
    }
};

// Bottom up 
class Solution {
public:
    int mod = 1e9+7;
    int numRollsToTarget(int n, int k, int target) {

        vector<vector<int>>t(n+1,vector<int>(target+1,0));

        t[0][0] = 1;

        for(int i=1;i<=n;i++)
        {
            // dice = i
            // target = j
            for(int j=1;j<=target;j++)
            {
                int ways = 0;
                for(int face = 1;face<=k;face++)
                {
                    if (j - face >= 0) {
                        ways = (ways + t[i - 1][j - face]) % mod;
                    }
                }
                t[i][j] = ways;
                
            }
        }
        return t[n][target];
        
    }
};