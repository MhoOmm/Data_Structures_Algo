// VVIP QUESTION
class Solution {
public:
    int n;
    bool solve(int mid,vector<int>&nums)
    {
        
        vector<long long>arr(begin(nums),end(nums));
        for(int i=0;i<n-1;i++)
        {
            if(arr[i]>mid)
            {
                return false;
            }
            long long buffer=mid-arr[i];
            arr[i+1]=arr[i+1]-buffer;
            
        }
        return arr[n-1]<=mid;
    }
    int minimizeArrayValue(vector<int>& nums) {

        n=nums.size();
        int start=1;
        int finish=*max_element(begin(nums),end(nums));
        int result=0;
        while(start<=finish){
            int mid=start+(finish-start)/2;
            if(solve(mid,nums)){
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