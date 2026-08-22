class Solution {
public:
    int divret(int n)
    {

        int sum = 0;
        int prod = 1;
        while(n>0)
        {
            int r = n%10;
            sum+=r;
            prod*=r;
            n = n/10;
        }
        return sum+prod;
    }
    bool checkDivisibility(int n) {
        int div = divret(n);
        if(div==0)return false;
        return n % div == 0;
    }
};