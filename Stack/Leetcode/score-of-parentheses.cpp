class Solution {
public:
    int scoreOfParentheses(string s) {
        int n = s.length();
        int sum = 0;
        stack<char>st;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='(')
            {
                // starting a new ()
                st.push(sum);
                sum = 0;
            }
            else{
                // ')'
                if(s[i-1]=='(')
                {
                    //nested case
                    sum = st.top() + 1;
                }else{
                    // '('
                    sum = st.top() + 2*sum;
                }
                st.pop();
            }
        }
        return sum;
    }
};