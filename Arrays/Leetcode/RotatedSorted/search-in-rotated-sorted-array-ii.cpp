class Solution {
public:
    bool binarySearch(vector<int>& nums, int target,int l,int r)
    {
        while(l<=r)
        {
            int mid  = l+(r-l)%2;
            if(nums[mid]==target)
            {
                return true;
            }else if(nums[mid]<target)
            {
                l = mid+1;
            }else{
                r = mid-1;
            }
        }
        return false;
    }
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        int peak = 0 ;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                peak = i;
            }
        }

        int first = binarySearch(nums,target,0,peak);
        int second = binarySearch(nums,target,peak+1,n-1);
        return first||second;
    }
};