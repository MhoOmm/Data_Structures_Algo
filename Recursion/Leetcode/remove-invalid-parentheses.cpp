class Solution {
public:
    int n;
    vector<string>result;
    int maxLen = 0;
    unordered_set<string>st;
    void solve(int i,int score,string &temp,string& s)
    {
        // invalid case
        if(score<0)
        {
            return;
        }
        if(i == n) {
            if(score == 0) {
                if(temp.length() > maxLen) {
                    maxLen = temp.length();
                    st.clear();
                }
                if(temp.length() == maxLen){
                    st.insert(temp);
                }
            }
            return;
        }
        // skip curr bracket
        if(s[i]=='(' || s[i]==')')
        {
            solve(i+1,score,temp,s);
        }
        // keep current bracket
        temp.push_back(s[i]);
        // Open bracket
        if(s[i]=='(')
        {
            solve(i+1,score+1,temp,s);
        }
        // Close bracket
        else if(s[i]==')')
        {
            solve(i+1,score-1,temp,s);
        }
        else{
            solve(i+1,score,temp,s);
        }
        temp.pop_back();

    }
    vector<string> removeInvalidParentheses(string s) {
        n = s.length();
        string temp = "";
        solve(0,0,temp,s);
        return vector<string>(st.begin(),st.end());
    }
};