class Solution {
public:
    bool solve(int mid,vector<int>& nums, int mo)
    {   
        long long  top=0;
        for(auto num:nums)
        {   
            int op=num/mid;
            if(num%mid==0)
            {
                op-=1;
            }
            top+=op;
        }
        return top<=mo;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size();
        int start=1;
        int finish=*max_element(nums.begin(),nums.end());
        int result=finish;
        int mo=maxOperations;
        while(start<=finish)
        {
            int mid=start+(finish-start)/2 ;
            if(solve(mid ,nums,mo)==true)
            {
                result=mid;
                finish=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return result;
    }
};