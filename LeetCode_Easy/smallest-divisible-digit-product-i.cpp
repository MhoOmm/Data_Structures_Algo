class Solution {
public:
    int sum(int n)
    {
        int prod = 1; 
        while(n>0)
        {
            int r = n%10;
            prod *= r;
            n = n/10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        int ans = 0;
        for(int i=n;i<=100;i++)
        {
            if(sum(i) % t==0)
            {
                ans = i;
                break;
            }
        }
        return ans;
    }
};