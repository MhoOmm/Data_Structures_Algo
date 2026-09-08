class Solution {
public:
    long long countCommas(long long n) {
        if(n<1000)
        {
            return 0;
        }
        long long result = 0;
        int numcom = 1;
        long long lb = 1000;
        while(lb <= n)
        {
            long long ub = lb*1000 - 1;
            if(ub>n)
            {
                ub = n;
            }
            result += (ub-lb+1)*numcom;
            numcom+=1;
            lb = lb*1000;
        }
        return result;
    }
};