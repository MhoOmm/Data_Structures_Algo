class Solution {
public:
    int minPairSum(vector<int>& nums) {
        int n = nums.size();
        sort(begin(nums),end(nums));

        int maxEle = -1;
        int i = 0;
        int j = n-1;
        while(i<=j)
        {
            maxEle = max(maxEle,nums[i]+nums[j]);
            i++;
            j--;
        }

        return maxEle;
    }
};