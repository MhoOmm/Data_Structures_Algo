class Solution {
public:
    bool divideArray(vector<int>& nums) {
        int n  = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int count = 0 ;
        for(auto &it:mp)
        {
            count+= ((it.second)/2);
        }
        return count==n/2;
    }
};