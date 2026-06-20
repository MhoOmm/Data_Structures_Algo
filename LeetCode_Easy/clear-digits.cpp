// stack solution 
// SC = O(n)  
// TC = O(n)

class Solution {
public:
    string clearDigits(string s)
    {
        stack<char>st;
        int n=s.length();

        int i=0;

        while(i<s.length())
        {
            if(!isdigit(s[i]))
            {
                st.push(s[i]);
            }
            else{
                st.pop();
            }
            i++;
        }

        string sn="";

        while(!st.empty())
        {
            sn.push_back(st.top());
            st.pop();
        }

        reverse(begin(sn),end(sn));
        return sn;
    }

};


// Optimised Approach single pass 
// TC = O(n) , SC = O(1)
class Solution {
public:
    string clearDigits(string s) {
        string ans = "";
        for(auto &ch:s)
        {
            if('0'<=ch && ch<='9')
            {
                ans.pop_back();
            }
            else{
                ans+=ch;
            }
        }

        return ans;
    }
};