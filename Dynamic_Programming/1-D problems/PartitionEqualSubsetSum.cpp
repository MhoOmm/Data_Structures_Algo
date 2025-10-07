// Resursion + Memoization
class Solution {
public:
    vector<vector<int>> t;
    bool solve(int i,vector<int>&nums,int sum)
    {
        if(i>=nums.size()|| sum < 0)
        {
            return false;
        }
        if(sum ==0){
            return true;
        }

        if(t[i][sum]!=-1)
        {
            return t[i][sum];
        }

        bool take = solve(i+1,nums,sum-nums[i]);
        bool skip =  solve(i+1,nums,sum);

        return t[i][sum] = take||skip;
    }
    bool canPartition(vector<int>& nums) {

        int n = nums.size();
        int sum = 0;
        for(int i=0;i<n;i++)
        {
            sum += nums[i];
        }
        t.assign(n + 1, vector<int>(sum + 1, -1));
        if(sum%2!=0)
        {
            return false;
        }
        return solve(0,nums,sum/2); 
    }
};


// Bottom-Up
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += nums[i];
        }

        if(sum % 2 != 0)
            return false;

        int target = sum / 2;
        vector<vector<bool>> t(n + 1, vector<bool>(target + 1, false));

        for(int i = 0; i <= n; i++) {
            t[i][0] = true;
        }

        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= target; j++) {
                bool notTake = t[i - 1][j];
                bool take = false;
                if(nums[i - 1] <= j) {
                    take = t[i - 1][j - nums[i - 1]];
                }
                t[i][j] = take || notTake;
            }
        }

        return t[n][target];
    }
};

