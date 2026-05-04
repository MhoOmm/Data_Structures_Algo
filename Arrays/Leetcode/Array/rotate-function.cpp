// brute force - O(n^2)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        for(int i=0;i<n;i++)
        {
            nums.push_back(nums[i]);
        }
        int i = 0;
        int j = n;
        int maxSum = INT_MIN;
        while(i<n){
            int sum= 0;
            int it = 0;
            for(int k=i;k<j;k++)
            {
                sum+=(it*nums[k]);
                it++;
            }
            maxSum = max(sum,maxSum);
            i++;
            j++;
        }
        return maxSum;
    }
};

// optimal - O(n)

class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        int fk = 0;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            fk+=(i*nums[i]);
        }
        int k=0;
        int maxSum = fk;
        while(k<n)
        {
            int fkn = fk + sum - n*nums[n-1-k];
            maxSum = max(maxSum,fkn);
            k++;
            fk = fkn;
        }

        return maxSum;
    }
};