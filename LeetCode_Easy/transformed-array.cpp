class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n= nums.size();
        vector<int>result;

        for(int i=0;i<n;i++)
        {
            int idx = nums[i];
            if(nums[i]>0)
            {
                result.push_back(nums[(i+idx)%n]);
            }else if(nums[i]<0){
                if((idx+i) > 0 )
                {
                    result.push_back(nums[i+idx]);
                }else{
                    int new_idx = ((i+idx)%n + n)%n;
                    result.push_back(nums[new_idx]);
                }
            }else{
                result.push_back(nums[i]);
            }
        }

        return result;
    }
};