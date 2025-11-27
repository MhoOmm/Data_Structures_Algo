class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {

        int n = nums.size();
        vector<long long>prefixSum(n,0);
        prefixSum[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }

        long long result = LLONG_MIN;

        for(int start=0;start<k;start++)
        {
            int i  = start;
            long long currSum = 0;

            while(i<n && i+k-1<n)
            {
                int j = i+k-1;
                long long subSum = prefixSum[j] - (i > 0 ? prefixSum[i-1] : 0);

                currSum = max(subSum,subSum+currSum);
                result = max(currSum,result);
                i=i+k; 
            } 
        }

        return result;
        
    }
};