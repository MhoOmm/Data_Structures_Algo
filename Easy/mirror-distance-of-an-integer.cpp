class Solution {
public:
    int reverse(int n){
        int num =0;
        while(n>0)
        {
            int r = n%10;
            num = num*10 + r;
            n = n/10;
        }

        return num;
    }
    int mirrorDistance(int n) {
        int rev  = reverse(n);
        return abs(rev-n);
    }
};