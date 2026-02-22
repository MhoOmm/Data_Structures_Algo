// TC = O(nlogn) & SC= O(1)
class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-1;i++)
        {
            if(nums[i]==nums[i+1])
            {
                ans.push_back(nums[i]);
            }
        }
        return ans;
    }
};

// optimal approach Tc : O(n) SC: O(1)
// always when the array number is within the range  1 <= nums[i] <= n
// use the index as markers

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            int idx = abs(nums[i]) - 1;
            if(nums[idx]<0)// already visited
            {
                ans.push_back(abs(nums[i]));
            }else{
                nums[idx] = -1*nums[idx];
            }
        }
        return ans;
    }
};