// brute force
class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int,int>mp;// number->freq
        for (int i = 0; i <= n - k; i++) {
            unordered_set<int> seen;
            for (int j = i; j < i + k; j++) {
                seen.insert(nums[j]);
            }
            for (int x : seen) {
                mp[x]++;
            }
        }
        int maxEleWithOneFreq = -1;
        for(auto &it:mp)
        {
            int num = it.first;
            int freq = it.second;
            if(freq==1)
            {
                maxEleWithOneFreq = max(maxEleWithOneFreq,num);
            }
        }
        return maxEleWithOneFreq;
    }
};
