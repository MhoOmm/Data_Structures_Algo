// recursion and memoization
class Solution {
    public:
        int m=1000000007;
        int t[1001];
    
        int solve(int n)
        {
            if(n==1||n==2)
            {
                return n;
            }
            if(n==3)return 5;
            if(t[n]!=-1)
            {
                return t[n];
            }
    
            return t[n]=(2*solve(n-1)%m+solve(n-3)%m)%m;
        }
        int numTilings(int n) {
            memset(t,-1,sizeof(t));
            return solve(n);
            
        }
    };

// bottom up 

class Solution {
    public:
        int m=1000000007;
        int numTilings(int n) {
            vector<int>t(n+1,0);
            if(n==1||n==2)
            {
                return n;
            }
            if(n==3)
            {
                return 5;
            }
            t[1]=1;
            t[2]=2;
            t[3]=5;
            for(int i=4;i<=n;i++)
            {
                t[i]=(2*t[i-1]%m + t[i-3] % m ) % m;
            }
    
            return t[n];
            
        }
    };
