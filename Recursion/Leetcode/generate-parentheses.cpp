class Solution {
public:
    vector<string>result;
    int N;
    void solve(int count,int open,int close,string temp)
    {
        if(count==0)
        {
            if(open==close)
            {
                result.push_back(temp);
                return;
            }
        }
        // invalid case
        if(close>open)
        {
            return;
        }
        // open
        if(open < N)
        {
            solve(count - 1, open + 1, close, temp + '(');
        }
        // close
        if(close < open)
        {
            solve(count - 1, open, close + 1, temp + ')');
        }
    }
    vector<string> generateParenthesis(int n) {
        N = n;
        solve(2*n,0,0,"");
        return result;
    }
};