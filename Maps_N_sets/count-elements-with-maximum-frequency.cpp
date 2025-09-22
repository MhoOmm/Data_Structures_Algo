class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        int maxFreq = INT_MIN;
        for(auto &num:nums){
            mp[num]++;
            maxFreq=max(maxFreq,mp[num]);
        }
        int count  = 0;


        for(auto &it:mp)
        {
            int ele = it.first;
            int freq = it.second;
            if(freq==maxFreq)
            {
                count+=maxFreq;
            }
        }

        return count;
        
    }
};