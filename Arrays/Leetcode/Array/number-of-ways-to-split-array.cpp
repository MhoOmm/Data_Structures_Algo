class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {

        int n = nums.size();
        vector<long long>prefixSum(n,0);

        prefixSum[0] = nums[0];

        for(int i=1;i<n;i++)
        {
            prefixSum[i] = nums[i]+prefixSum[i-1];
        }
        int count =0;

        for(int i=0;i<n-1;i++)
        {
            long long left = prefixSum[i];
            long long right = prefixSum[n-1] - prefixSum[i];
            if(left >= right)
            {
                count++;
            }
        }

        return count;
        
    }
};