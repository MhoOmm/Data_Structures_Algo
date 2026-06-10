class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int n = nums.size();
        long long  maxn = INT_MIN;
        long long minn = INT_MAX;

        for(int i=0;i<n;i++)
        {
            if(nums[i]>maxn)
            {
                maxn = nums[i];
            }
            if(nums[i]<minn)
            {
                minn = nums[i];
            }
        }

        return (maxn-minn)*k;
    }
};