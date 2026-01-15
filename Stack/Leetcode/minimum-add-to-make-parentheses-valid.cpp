class Solution {
public:
    int minAddToMakeValid(string s) {
        int n  = s.length();
        stack<char>st;

        for(int i=0;i<n;i++)
        {
            if(!st.empty() && st.top()=='(' && s[i]==')')
            {
                st.pop();
            }else{
                st.push(s[i]);
            }
        }
        int count =0;
        if(st.empty())
        {
            return 0;
        }else{
            while(!st.empty())
            {
                count++;
                st.pop();
            }
        }
        return count;
    }
};