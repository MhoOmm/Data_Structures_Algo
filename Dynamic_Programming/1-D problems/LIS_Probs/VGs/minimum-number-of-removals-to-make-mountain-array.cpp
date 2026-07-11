class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        int n = nums.size();
        // building lis array
        vector<int>lis(n,1);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[i]>nums[j])
                {
                    lis[i] = max(lis[i],lis[j]+1);
                }
            }
        }
        // building lds array
        vector<int>lds(n,1);
        for(int i=n-1;i>=0;i--)
        {
            for(int j=i+1;j<n;j++)
            {
                if(nums[j]<nums[i])
                {
                    lds[i] = max(lds[i],lds[j]+1);
                }
            }
        }

        // calculate the min number of (removal)
        int removal = n; // max value
        for(int i =0;i<n;i++)
        {
            if(lis[i]>1 && lds[i]>1){ // only then the mountain length will be 3
                removal = min(removal,n+1-(lis[i]+lds[i]));
            }
        }
        return removal;
    }
};