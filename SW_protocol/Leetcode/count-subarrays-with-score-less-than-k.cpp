class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) {
        
        int n= nums.size();
        long long count = 0;
        int i =0;
        int j =0;
        long long currsum = 0;
        while(j<n)
        {
            currsum += nums[j];
            while((currsum * (j-i+1))>=k)
            {
                currsum -= nums[i];
                i++;
                
            }
            long long product = currsum * (j-i+1);
            if(product<k)
            {
                count+=(j-i+1);
            }
            j++;
        }

        return count;
    }
};