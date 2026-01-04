class Solution {
public:
    int findSum(int num)
    {
        int sum =0;
        int div = 0;
        for(int i=1;i*i<=num;i++)
        {
            if(num%i==0)
            {
                int other = num/i;
                if(i==other)
                {
                    div+=1;
                    sum+=i;
                }else{
                    div+=2;
                    sum+=(other+i);
                }
            }
        }
        return div==4?sum:0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int n = nums.size();
        int result=0;
        for(int i=0;i<n;i++)
        {
            result += findSum(nums[i]);
        }
        return result;
    }
};