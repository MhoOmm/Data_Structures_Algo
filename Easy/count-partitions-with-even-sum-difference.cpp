class Solution {
public:
    int countPartitions(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixSum(n,0);
        prefixSum[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }

        int count = 0;

        for(int i=0;i<n-1;i++)
        {
            int leftSum = prefixSum[i];
            int rightSum = prefixSum[n-1]-prefixSum[i];
            if((rightSum-leftSum)%2 == 0)
            {
               count++;
            }
        }

        return count;
        
    }
};