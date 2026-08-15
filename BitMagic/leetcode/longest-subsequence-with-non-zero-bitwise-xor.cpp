class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int n = nums.size();
        int xorOut = 0;
        int zero = 0;
        // corner case -> all elements zero
        for(int i =0;i<n;i++)
        {
            if(nums[i]==0)
            {
                zero++;
            }
            xorOut ^= nums[i];
        }
        if(zero==n)
        {
            return 0;
        }
        return xorOut == 0? n-1:n;
    }
};