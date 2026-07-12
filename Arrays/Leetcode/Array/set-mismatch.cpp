// brute force O(n) tc & sc
class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        int miss = -1;
        int dupl = -1;
        for(int i=1;i<=n;i++)
        {
            if (mp[i] == 2)
                dupl = i;
            else if (mp[i] == 0)
                miss = i;
        }
        return {dupl,miss};
    }
};

// optimal solution O(n) tc & sc = O(1)

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int miss = -1;
        int dupl = -1;
        for(int i=0;i<n;i++)
        {
            if(nums[abs(nums[i])-1] < 0)
            {
                dupl = abs(nums[i]);
            }else{
               nums[abs(nums[i])-1]*=-1; 
            }
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
            {
                miss = i+1;
                break;
            }
        }
        return {dupl,miss};
    }
};