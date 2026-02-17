// Sliding window with some tweaks
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int k) {
        int n = nums.size();
        int i =0;
        int j =0;
        int count =0;
        int sum =0;
        int prefixZ =0;
        while(j<n)
        {
            sum+=nums[j];
            while(i<j && (nums[i]==0 || sum>k))
            {
                if(nums[i]==0)
                {
                    prefixZ ++;
                }else{
                    prefixZ = 0;
                }
                sum-=nums[i];
                i++;
            }
            if(sum==k)
            {
                count+= 1+prefixZ;
            }
            j++;
        }

        return count;
    }
};