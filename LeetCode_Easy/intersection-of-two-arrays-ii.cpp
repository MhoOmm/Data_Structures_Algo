class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        int n  = nums1.size();
        int m = nums2.size();

        unordered_map<int,int>mp;
        for(auto &num:nums1)
        {
            mp[num]++;
        }

        vector<int>result;

        for(int i =0;i<m;i++)
        {
           if(mp[nums2[i]]>0){
            result.push_back(nums2[i]);
            mp[nums2[i]]--;
           }
        }

        return result;
        
    }
};