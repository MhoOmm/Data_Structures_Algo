class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int l = 0;
        int r = n-1;
        int ans = 0;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(arr[mid]<arr[mid+1])
            {
                l = mid+1;
            }else if(arr[mid]<arr[mid-1])
            {
                r = mid-1;
            }else{
                ans = mid;
                break;
            }
        }

        return ans;
    }
};