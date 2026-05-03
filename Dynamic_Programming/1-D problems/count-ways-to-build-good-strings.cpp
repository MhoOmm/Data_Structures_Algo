// recurr + memo

class Solution {
public:
    int mod = 1e9+7;
    vector<int>t;
    int solve(int length,int l,int h,int z,int o)
    {
        if(length>h)
        {
            return 0;
        }
        int count =0;
        if(length>=l)
        {
            count=1;
        }
        if(t[length]!=-1)
        {
            return t[length];
        }
        // take one
        int one = solve(length+o,l,h,z,o);
        // take zero
        int zero = solve(length+z,l,h,z,o);

        return t[length] = (count+one+zero)%mod;
    }
    int countGoodStrings(int low, int high, int zero, int one) {
        t.resize(high+1,-1);
        return solve(0,low,high,zero,one);
    }
};