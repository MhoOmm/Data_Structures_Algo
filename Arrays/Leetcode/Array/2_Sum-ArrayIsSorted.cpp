// brute force
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int>result;
        for( int i = 0;i<n;i++)
        {
            for(int j =i+1;j<n;j++)
            {

                if(nums[i]+nums[j]==target)
                {
                    return {i+1,j+1};
                }
            }
        }

        return {};
    }
};

// optimal approach:two pointer
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        int i = 0 ;
        int j = n-1;

        while(i<j)
        {
            int sum = nums[i]+nums[j];
            if(sum==target)
            {
                return {i+1,j+1};
            }
            else if(sum<target)
            {
                i++;
            }else{
                j--;
            }
        }

        return {};

    }
};