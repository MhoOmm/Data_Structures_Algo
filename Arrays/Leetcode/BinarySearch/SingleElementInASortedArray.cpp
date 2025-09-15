class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int start=0;
        int finish=n-1;
        int result=0;
        while(start<finish)
        {
            int mid= start+(finish-start)/2;
            bool iseven;
            if((finish-mid)%2==0)
            {
                iseven=true;
            }else{
                iseven=false;
            }
            if(nums[mid+1]==nums[mid])
            {
                if(iseven)
                {
                    start=mid+2;
                }else{
                    finish=mid-1;
                }
            }else{
                 if(iseven)
                {
                    finish=mid;
                }else{
                    start=mid+1;
                }
            }
        }
        return nums[finish];
    }
};