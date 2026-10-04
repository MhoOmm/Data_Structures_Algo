class Solution {
public:
    int n;
    int t[101][101];
    bool solve(int i,int count,string &s)
    {
        if(count<0)
        {
            return false;
        }
        if(i>=n)
        {
            return count==0;
        }
        if(t[i][count]!=-1)
        {
            return t[i][count];
        }
        // open bracket case
        if(s[i]=='(')
        {
            return t[i][count]= solve(i+1,count+1,s);
        }
        // close bracket case
        if(s[i]==')')
        {
            return t[i][count]= solve(i+1,count-1,s);
        }
        // * case
        bool ob,cb,empty;
        if(s[i]=='*')
        {
            ob = solve(i+1,count+1,s);
            cb = solve(i+1,count-1,s);
            empty = solve(i+1,count,s);
        }
        return t[i][count] = ob||cb||empty;
    }
    bool checkValidString(string s) {
        n = s.length();
        memset(t,-1,sizeof(t));
        return solve(0,0,s);
    }
};