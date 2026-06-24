// tle o(n*m^2)
class Solution {
public:
    int l,r,n;
    int mod  = 1e9+7;
    long long t[2001][2001][2];
    int solve(int i,int prev,bool parity)
    {
        if(i==n)
        {
            return 1; // successfully found one path
        }
        long long sum =0;
        if(t[i][prev][parity]!=-1)
        {
            return t[i][prev][parity];
        }
        if(parity){
            // increasing number next
            for(int next=prev+1;next<=r;next++){
                sum = (sum + solve(i+1,next,false))%mod;
            }
        }else{
            for(int next=l;next<prev;next++){
                sum = (sum + solve(i+1,next,true))%mod;
            }
        }
        return t[i][prev][parity] = sum%mod;
    }
    int zigZagArrays(int N, int L, int R) {
        n = N;
        l = L;
        r = R;

        long long ans = 0;
        memset(t,-1,sizeof(t));
        for (int start = l; start <= r; start++) {
            ans = (ans + solve(1, start, 1)) % mod;
            ans = (ans + solve(1, start, 0)) % mod;
        }

        return ans;
    }
};

// bottom up 
