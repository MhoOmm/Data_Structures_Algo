// brute force
class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp=0;
        for(int i =0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(nums[i]<=nums[j])
                {
                    ramp=max(ramp,j-i);
                }
            }
        }

        return ramp;
    }
};

// better approach:Traverse from the right in j 
// so that ek baar agar ans milgya to aur aage nhi jana padega

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        int ramp=0;
        for(int i =0;i<n;i++)
        {
            for(int j=n-1;j>i;j--)
            {
                if(nums[i]<=nums[j])
                {
                    ramp=max(ramp,j-i);
                }
            }
        }

        return ramp;
    }
};


// optimal approach


class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int n = nums.size();
        vector<int>maxRight(n);
        maxRight[n-1] = nums[n-1];
        for(int i=n-2;i>=0;i--)
        {
            maxRight[i]=max(maxRight[i+1],nums[i]);
        }

        int j = 0;
        int i = 0;
        int ramp = 0;
        while(j<n)
        {
            while(i<j && nums[i]>maxRight[j] )
            {
                i++;
            }
            ramp = max(ramp,j-i);
            j++;
            
        }


        return ramp;
    }
};