// Good Question - see video once for revising everything in kadane's algo
class Solution {
public:
    int kadaneMax(vector<int>&nums,int n)
    {
        int maxSum = nums[0];
        int currSum = nums[0];

        for(int i=1;i<n;i++)
        {
            currSum = max(nums[i],currSum+nums[i]);
            maxSum = max(currSum,maxSum);
        }

        return maxSum;
    }

    int kadaneMin(vector<int>&nums,int n)
    {
        int minSum = nums[0];
        int currSum = nums[0];

        for(int i=1;i<n;i++)
        {
            currSum = min(nums[i],currSum+nums[i]);
            minSum = min(currSum,minSum);
        }

        return minSum;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();

        int sum = accumulate(nums.begin(),nums.end(),0);

        // maxSum

        int maxSum = kadaneMax(nums,n);
        int minSum = kadaneMin(nums,n);

        int circSum = sum - minSum;

        return maxSum>0? max(circSum,maxSum):maxSum;

    }
};