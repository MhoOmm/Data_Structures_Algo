class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        unordered_set<int>st(nums.begin(),nums.end());

        int it = 1;
        while(true)
        {
            int num = k*it;
            if(!st.count(num))
            {
                return num;
            }
            it++;
        }
    }
};