// Cumulative Sum Approach
class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int sum =0;
        unordered_map<int,int>mp;
        mp.insert({0,1});
        int count = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int diff = sum-k;
            if(mp.find(diff)!=mp.end())
            {
                count+=mp[diff];
            }
            mp[sum] += 1;
        }
        return count;
    }
};