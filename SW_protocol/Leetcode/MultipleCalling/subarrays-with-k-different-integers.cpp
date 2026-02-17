class Solution {
public:
    int subarr(vector<int>& nums, int k)
    {
        int n= nums.size();
        int i=0;
        int j=0;
        int count = 0;
        unordered_map<int,int>freq;
        while(j<n)
        {
            freq[nums[j]]++;
            while(freq.size()>k)
            {
                freq[nums[i]]--;
                if(freq[nums[i]]==0)
                {
                    freq.erase(nums[i]);
                }
                i++;
            }
            count += j-i+1;
            j++;
        }
        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        int n = nums.size();
        return subarr(nums,k)-subarr(nums,k-1);
    }
};