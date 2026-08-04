// brute force-> using set
class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());

        int start = *min_element(nums.begin(),nums.end());
        int end = *max_element(nums.begin(),nums.end());
        vector<int>ans;
        for(int i=start;i<=end;i++)
        {
            if(!st.count(i))
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};