class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        long long Sum = 0;

        int i =0;
        int j =0;
        unordered_map<int,int>mp;
        long long currSum =0;
        while(j<n)
        {
            mp[nums[j]]++;
            currSum+=nums[j];
            while(mp[nums[j]]>1)
            {
                mp[nums[i]]--;
                currSum-=nums[i];
                i++;
            }
            if (j - i + 1 > k) {
                mp[nums[i]]--;
                currSum -= nums[i];
                i++;
            }
            if((j-i+1) == k)
            {
                Sum =max(Sum,currSum);
            }
            j++;
        }

        return Sum;
    }
};