// similar to problem lc 2762
class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        int n = nums.size();
        int i =0;
        int j =0;
        int maxLength = 0;
        map<int,int>mp;
        while(j<n)
        {
            mp[nums[j]]++;
            while(!( abs(mp.rbegin()->first - mp.begin()->first) <= limit))
            {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                {
                    mp.erase(nums[i]);
                }
                i++;
            }
            maxLength = max(maxLength,j-i+1);
            j++;
        }
        return maxLength;
    }
};