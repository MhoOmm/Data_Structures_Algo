class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool>result(n);

        int reman = 0;
        for(int i =0;i<n;i++)
        {
           reman = (reman*2+nums[i])%5;
           result[i]=(reman==0);
        }

        return result;
        
    }
};