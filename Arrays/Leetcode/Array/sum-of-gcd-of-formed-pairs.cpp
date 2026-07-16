class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int>prefixGcd(n);
        int maxele = 0;

        for(int i=0;i<n;i++)
        {
            maxele = max(nums[i],maxele);
            prefixGcd[i] =gcd(nums[i],maxele);
        }
        sort(prefixGcd.begin(),prefixGcd.end());
        int i = 0;
        int j = n-1;
        long long result = 0;
        while(i<j)
        {
            result += gcd(prefixGcd[i],prefixGcd[j]);
            i++;
            j--;
        }

        return result;
    }
};