class Solution {
public:
    int minimumPairRemoval(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        while(!is_sorted(nums.begin(),nums.end())){
            int  idx =0;
            int minSum = INT_MAX;
            int n = nums.size();
            for(int i=0;i<n-1;i++)
            {
                int sum = nums[i] + nums[i+1];
                if(sum<minSum)
                {
                    minSum = sum;
                    idx = i;
                }
            }
            nums[idx] = nums[idx]+nums[idx+1];
            nums.erase(nums.begin()+idx+1);
            count++ ;
        }

        return count;
    }
};