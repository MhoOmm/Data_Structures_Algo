class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int n = nums.size();
        int out =0;
        for(int i =0;i<n;i++)
        {
            string num = to_string(nums[i]);
            if(num.length()%2==0)
            {
                out ++;
            }
        }

        return out ;
    }
};