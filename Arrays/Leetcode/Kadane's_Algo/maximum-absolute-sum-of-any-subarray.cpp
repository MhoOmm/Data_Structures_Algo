class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {

        int n = nums.size();

        // maxsum calc

        int maxSum =nums[0];
        int currSum = nums[0];

        for(int i=1;i<n;i++)
        {
            currSum = max(currSum+nums[i],nums[i]);// yahan se naya chalu karoon ya append in prev subarray
            maxSum  = max(currSum,maxSum);
        }

        // min Sum subarray calc

        int minSum = nums[0];
        int mSum = nums[0];

        for(int i =1;i<n;i++)
        {
            mSum = min(nums[i],nums[i]+mSum);
            minSum = min(minSum,mSum);
        }

        return max(maxSum,abs(minSum));
        
    }
};