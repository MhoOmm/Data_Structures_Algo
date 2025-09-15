// recursion + memoization
class Solution {
public:
    int t[10001][201]; // Change to int

    bool solve(vector<int>& arr, int sum, int n) {
        if (sum == 0) return true;
        if (n == 0) return false;
        if (t[sum][n] != -1) return t[sum][n];

        if (arr[n - 1] > sum)
            return t[sum][n] = solve(arr, sum, n - 1);

        bool take = solve(arr, sum - arr[n - 1], n - 1);
        bool skip = solve(arr, sum, n - 1);

        return t[sum][n] = take || skip;
    }
    bool canPartition(vector<int>& nums) {

        int n=nums.size();
        int sum=0;
        memset(t,-1,sizeof(t));
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2 != 0)
        {
            return false;
        }else{
            return solve(nums,sum/2,n);
        }
        
    }
};

// bottom up approach

class Solution {
public:
    
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
        }
        if(sum%2 != 0)
        {
            return false;
        }
        
        int target = sum / 2;
        vector<vector<bool>> t(target + 1, vector<bool>(n + 1, false));
        for (int j = 0; j <= n; j++) {
            t[0][j] = true;
        }
        for (int i = 1; i <= target; i++) {
            for (int j = 1; j <= n; j++) {
                if (nums[j - 1] > i) {
                    t[i][j] = t[i][j - 1];
                } else {
                    t[i][j] = t[i][j - 1] || t[i - nums[j - 1]][j - 1];
                }
            }
        }

        return t[target][n];
    }
};
