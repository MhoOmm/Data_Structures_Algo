class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int n = nums.size();

        int evenl=0;
        int oddl=0;
        int altl = 1;

        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
            {
                evenl++;
            }else{
                oddl++;
            }
        }

        int parity=nums[0]%2;

        for(int i = 1 ;i<n;i++)
        {
            int currParity=nums[i]%2;
            if(currParity != parity)
            {
                altl++;
                parity = currParity;
            }
        }

        return max({altl,evenl,oddl});
    }
};