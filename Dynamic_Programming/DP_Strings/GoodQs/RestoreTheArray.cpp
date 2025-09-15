class Solution {
public:
    int  n;
    int t[100001];
    const int mod = 1e9+7;
    int solve(int i,string&s,int k)
    {
        if(i>=n)
        {
            return 1;
        }
        if(s[i]=='0')
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        long ans=0;
        long num=0;
        for(int end=i;end<s.length();end++){

            num=(num*10)+(s[end]-'0');
            if(num>k)
            {
                break;
            }
            ans=(ans%mod+solve(end+1,s,k)%mod)%mod;

        }
        return t[i]=ans;
    }
    int numberOfArrays(string s, int k) {

        n=s.length();
        memset(t,-1,sizeof(t));
        return solve(0,s,k);
        
    }
};