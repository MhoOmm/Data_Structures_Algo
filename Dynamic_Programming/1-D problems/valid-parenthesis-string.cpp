class Solution {
public:
    int t[101][101];
    bool solve(int i,int sum,string &s)
    {
        if (sum < 0)
            return false;
        if(i>=s.length())
        {
            return sum==0;
        }
        if(t[i][sum]!=-1)
        {
            return t[i][sum];
        }
        if(s[i]=='(')
        {
            return t[i][sum] = solve(i+1,sum+1,s);
        }else if(s[i]==')')
        {
            return t[i][sum] = solve(i+1,sum-1,s);
        }
        bool ans = false;
        bool ob = false, nb = false, cb = false;
        if(s[i]=='*')
        {
            ob = solve(i+1,sum+1,s);
            nb = solve(i+1,sum,s);
            cb = solve(i+1,sum-1,s);
        }
        return t[i][sum] = ob||nb||cb;
    }
    bool checkValidString(string s) {
        memset(t,-1,sizeof(t));
        return solve(0,0,s);
    }
};