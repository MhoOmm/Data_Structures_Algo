class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int>maxI(n,0);
        vector<int>minI(n,0);
        int maxi = nums[0];
        int mini = nums[n-1];
        for(int i=0;i<n;i++)
        {
            maxi = max(nums[i],maxi);
            maxI[i] = maxi;
        }
        for(int i=n-1;i>=0;i--)
        {
            mini = min(nums[i],mini);
            minI[i] = mini;
        }
        int small = -1;
        for(int i=0;i<n;i++)
        {
            int score = (maxI[i]-minI[i]);
            if(score <= k)
            {
                small = i;
                break;
            }
        }
        return small;
    }
};