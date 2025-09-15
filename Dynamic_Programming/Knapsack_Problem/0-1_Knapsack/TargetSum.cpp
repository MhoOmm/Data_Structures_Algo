// rescursion+memoization
class Solution {
public:
    int n;
    int t[21][2001];
    int offset=1000;
    int solve(int i,int sum,vector<int>& nums,int target){
        //base case
        if(i==n)
        {
            if(sum==target){
                return 1;
            }else{
                return 0;
            }
        }
        if(t[i][sum+offset]!=-1)
        {
            return t[i][sum+offset];
        }
       
        int plus=solve(i+1,sum+nums[i],nums,target);
        int minus=solve(i+1,sum-nums[i],nums,target);

        return t[i][sum+offset]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,nums,target);
    }
};

// alternate of memoization take a map
class Solution {
public:
    int n;
    int solve(int i,int sum,vector<int>& nums,int target,unordered_map<string,int>&mp){
        //base case
        if(i==n)
        {
            if(sum==target){
                return 1;
            }else{
                return 0;
            }
        }
        string key=to_string(i)+"_"+to_string(sum);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
       
        int plus=solve(i+1,sum+nums[i],nums,target,mp);
        int minus=solve(i+1,sum-nums[i],nums,target,mp);

        return mp[key]=plus+minus;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        n=nums.size();
        unordered_map<string,int>mp;
        return solve(0,0,nums,target,mp);
    }
};

// bottom up same as partition with subsemt sum diffrence (exact same code)
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int d) {
        int n=nums.size(); 
        int mod = 1e9 + 7;
        long long sum = accumulate(nums.begin(), nums.end(), 0LL);
        
        if ((sum + d) % 2 != 0 || sum < d) return 0;
        long long target = (sum + d) / 2;
        if (target > 100000) return 0;
        vector<vector<int>> t(n + 1, vector<int>(target + 1, 0));
        for (int i = 0; i <= n; i++) t[i][0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 0; j <= target; j++) {
                if (nums[i - 1] <= j)
                    t[i][j] = (t[i - 1][j] + t[i - 1][j - nums[i - 1]]) % mod;
                else
                    t[i][j] = t[i - 1][j];
            }
        }

        return t[n][target];
    }
};