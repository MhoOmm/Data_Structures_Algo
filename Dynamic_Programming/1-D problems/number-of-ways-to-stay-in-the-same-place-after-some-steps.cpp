class Solution {
public:
    int t[501][501];
    int mod = 1e9+7;
    int solve(int i, int steps,int arrLen)
    {
        if(i<0 || i>=arrLen){
            return 0;
        }
        if(i>steps) // no use cause cannot come back
        {
            return 0;
        }
        if(steps==0 )
        {
            return (i==0); // one path found
        }
        if(t[i][steps]!=-1)
        {
            return t[i][steps];
        }

        // stay
        long long stay = solve(i,steps-1,arrLen);
        // right
        long long right = solve(i+1,steps-1,arrLen);
        // left
        long long left  = solve(i-1,steps-1,arrLen);

        return t[i][steps] = (stay + right + left)%mod;
    }
    int numWays(int steps, int arrLen) {
        memset(t,-1,sizeof(t));
        return solve(0,steps,arrLen);
    }
};