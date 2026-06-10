// basic approach - will update optimal later
class Solution {
public:
    int digit(int num)
    {
        int sum = 0;
        while(num>0)
        {
            int r = num%10;
            sum += r;
            num = num/10;
        }

        return sum;
    }
    int minElement(vector<int>& nums) {
        int result = 37 ;// (9+9+9+9)
        for(int num:nums)
        {
            int sum = digit(num);
            result = min(result,sum);
        }
        return result;
    }
};