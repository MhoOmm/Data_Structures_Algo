class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0;
        int j = 0;
        int maxLength = 0;
        int countZ = 0;

        while(j<n)
        {
            if(nums[j]==0)
            {
                countZ+=1;
            }

            while(countZ > k)
            {
                if(nums[i]==0)
                {
                    countZ-=1;
                }
                i++;
            }
            if(countZ <= k)
            {
                maxLength = max(maxLength,j-i+1);
            }
            j++;
        }

        return maxLength;

    }
};