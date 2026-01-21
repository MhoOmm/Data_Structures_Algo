class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n  = nums.size();
        int counto = 0;
        for(int i =0;i<n;i++)
        {
            if(nums[i]==1) counto++;
        }

        int i =0;
        int j = 0;
        int result =0;
        int currone =0;
        int maxcount =0;
        while(j<2*n)
        {
            if(nums[j%n]==1)
            {
                currone++;
            }

            if(j-i+1 > counto)
            {
                currone-= nums[i%n];
                i++;
            }
            maxcount= max(maxcount,currone);
            j++;
        }

        return counto - maxcount;
    }
};