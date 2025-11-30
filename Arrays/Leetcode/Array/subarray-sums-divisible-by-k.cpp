// O(n^2)
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n = nums.size();
        vector<int>prefixSum(n,0);
        prefixSum[0] = nums[0];
        for(int i =1;i<n;i++)
        {
            prefixSum[i] = prefixSum[i-1]+nums[i];
        }
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum = prefixSum[j];
                if(i > 0) sum -= prefixSum[i - 1];
                if(sum%k==0)
                {
                    count++;
                }
            }
        }

        return count ;
    }
};

// optimal solution
// O(n)

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {

        int n= nums.size();
        unordered_map<int,int>mp;
        int count = 0;
        int sum =0;
        mp[0] = 1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int rem=sum%k;
            if(rem<0)
            {
                rem+=k;
            }

            if(mp.find(rem)!=mp.end())
            {
                count+=mp[rem];
            }
            mp[rem]++;
        }

        return count;
        
    }
};