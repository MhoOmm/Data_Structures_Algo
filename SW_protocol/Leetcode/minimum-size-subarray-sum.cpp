class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j = 0;
        long long sum = 0;
        int length = INT_MAX;

        while(j<n){
            sum+=nums[j];

            while(sum>=target)
            {
                length = min(length, j - i + 1);
                sum -= nums[i];
                i++;
            }
            j++;
        }

        return length==INT_MAX?0:length;
    }
};