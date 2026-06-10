// brute force O(n*5)
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int num = nums[i];
            if(num < 10)
            {
                ans.push_back(num);
                continue;
            }
            string temp = to_string(num);
            for(auto &ch:temp)
            {
                ans.push_back(ch-'0');
            }
        }

        return ans;
    }
};