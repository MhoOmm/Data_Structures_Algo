// brute force 
class Solution {
public:
    int longestBalanced(vector<int>& nums) {
        int n = nums.size();
        int maxCount = 0;
        for(int i =0;i<n;i++)
        {
            unordered_set<int>stodd;
            unordered_set<int>steven;
            for(int j=i;j<n;j++)
            {
                if(nums[j]%2 ==0)
                {
                    steven.insert(nums[j]);
                }  
                else{
                    stodd.insert(nums[j]);
                }  

                if(steven.size()==stodd.size())
                {
                    maxCount = max(maxCount,j-i+1);
                }
            }
        }

        return maxCount;
    }
};
