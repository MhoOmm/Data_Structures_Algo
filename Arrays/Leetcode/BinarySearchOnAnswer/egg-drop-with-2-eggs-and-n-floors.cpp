class Solution {
public:
    int twoEggDrop(int n) {
        int l = 0;
        int r = n;
        int ans = n;
        while(l<=r)
        {
            int mid = (l+r)/2;
            int floorsCovered = mid*(mid+1)/2;
            if(floorsCovered>=n)
            {
                // moves are enough but need minimum
                ans = mid;
                r = mid-1;
            }
            else{
                // moves are not enough
                l = mid+1;
            }
        }
        return ans;
    }
};