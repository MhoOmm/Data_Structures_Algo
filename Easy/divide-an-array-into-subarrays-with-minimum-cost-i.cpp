class Solution {
public:
    int minimumCost(vector<int>& nums) {
        int n = nums.size();
        if(n==3)return nums[0] + nums[1] + nums[2];
        int min1 = INT_MAX;
        int min2 = INT_MAX;

        for(int i=1;i<n;i++)
        {
            if(nums[i]<min1){
                min2 = min1;
                min1 = nums[i];
            }else if(nums[i]<min2){
                min2 = nums[i];
            }
        }
        

        return nums[0] + min1 + min2;
    }
};