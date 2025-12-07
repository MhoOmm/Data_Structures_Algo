class Solution {
public:
    int n;
    int t[1001][201];

    int solve(int i, int sum, int target, vector<int>& nums) {
        if (sum == target) {
            return 1;
        }
        if (i >= n || sum > target) {
            return 0;
        }
        if (t[sum][i] != -1) {
            return t[sum][i];
        }
        int take = solve(0, sum + nums[i], target, nums);
        int skip = solve(i + 1, sum, target, nums);

        return t[sum][i] = take + skip;
    }

    int combinationSum4(vector<int>& nums, int target) {
        n = nums.size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, target, nums); 
    }
};
