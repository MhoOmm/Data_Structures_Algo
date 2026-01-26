class Solution {
public:
    vector<vector<int>> minimumAbsDifference(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>result;
        int minDiff = INT_MAX;

        for(int i =0;i<n-1;i++)
        {
            minDiff = min(minDiff ,abs(nums[i+1]-nums[i]));
        }

        for(int i=0;i<n-1;i++)
        {
            if(abs(nums[i+1]-nums[i])==minDiff)
            {
                result.push_back({nums[i],nums[i+1]});
            }
        }

        return result;
    }
};