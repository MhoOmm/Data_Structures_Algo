class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n =  nums.size();
        int oddCount =0 ;
        unordered_map<int,int>mp;
        int count =0;
        mp.insert({0,1});

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2 !=0)
            {
                oddCount+=1;
            }

            int diff = oddCount-k;
            if(mp.find(diff)!=mp.end())
            {
                count+= mp[diff];
            }
            mp[oddCount]++;
        }

        return count;
    }
};