class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        long long maxSum = 0;

        sort(begin(nums),end(nums));
        long long total = 0;
        for(int i = 0;i<n;i++)
        {
            total+=nums[i];
        }
        for(int i=n-1;i>=2;i--)
        {
            total = total - nums[i];
            if(total>nums[i])
            {
                return total + nums[i];
            }
        }
        return -1;
    }
};