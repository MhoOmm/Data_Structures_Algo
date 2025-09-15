// optimal O(n)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        int minele = nums[0];

        for(int i=1;i<n;i++)
        {
            if(minele>nums[i])
            {
                minele=nums[i];
            }
            else{
                result=max(result,nums[i]-minele);
            }
        }

        return result==0?-1:result;
    }
};

// Brute Force O(n^2)
class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n = nums.size();
        int result = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++)
            {
                if(nums[j]>nums[i])
                {
                    result = max(result,nums[j]-nums[i]);
                }
            }

        }

        return result==INT_MIN?-1:result;
    }
};