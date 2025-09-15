class Solution {
public:
    int n;
    bool pair(int  mid,vector<int>& nums,int p)
    {
        int count = 0;
        int i=0;
        while(i<n-1){
            if(nums[i+1]-nums[i]<=mid)
            {
                i+=2;
                count++;
            }else{
                i++;
            }
        }
        return count>=p;
    }
    int minimizeMax(vector<int>& nums, int p) {
        n=nums.size();
        sort(begin(nums),end(nums));
        int l=0;
        int r=nums[n-1]-nums[0];
        int result= INT_MAX;
        while(l<=r){
            int mid= l+(r-l)/2;

            if(pair(mid,nums,p))
            {
                result=mid;
                r=mid-1;
            }else
            {
                l=mid+1;
            }  
        }

        return result;
    }
};