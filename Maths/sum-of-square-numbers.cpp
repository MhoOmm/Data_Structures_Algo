// brute force - finding a and then binary search for the next number
class Solution {
public:
    typedef long long ll;
    bool judgeSquareSum(int c) {
        for(ll a=0;a*a<=c;a++)
        {
            ll num = c - a*a;
            ll l = 0;
            ll r = sqrt(num);

            while(l<=r)
            {
                ll mid = l + (r-l)/2;
                ll square = mid * mid;

                if(square==num)
                {
                    return true;
                }
                if(square<num)
                {
                    l = mid+1;
                }else{
                    r = mid-1;
                }
            }

        }

        return false;
    }
};

// optmised approach -  binary search for sqrt

class Solution {
public:
    bool judgeSquareSum(int c) {
        long a = 0;
        long b = sqrt(c);
        while(a<=b)
        {
            long sum = a*a + b*b;
            if(sum==c)
            {
                return true;
            }
            else if(sum>c)
            {
                b--;
            }else{
                a++;
            }

        }
        return false;
    }

};