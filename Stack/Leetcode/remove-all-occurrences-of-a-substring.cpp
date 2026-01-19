// stack solution
class Solution {
public:
    bool check(stack<char>&st,string &part,int m)
    {
        stack<char>temp = st;
        for(int i=m-1;i>=0;i--)
        {
            if(part[i]!=temp.top())
            {
                return false;
            }
            temp.pop();
        }
        return true;
    }
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();

        stack<char>st;
        for(int i=0;i<n;i++)
        {
            st.push(s[i]);

            if(st.size()>=m && check(st,part,m)){
                int size = m;
                while(size--)
                {
                    st.pop();
                }
            }
        }

        string result = "";
        while(!st.empty())
        {
            result.push_back(st.top());
            st.pop();
        }
        reverse(begin(result),end(result));
        return result;
    }
};

// string as a stack
class Solution {
public:
    string removeOccurrences(string s, string part) {
        int n = s.length();
        int m = part.length();
        string temp = "";
        for(int i=0;i<n;i++)
        {
            temp.push_back(s[i]);
            if(temp.length()>=m && temp.substr(temp.length()-m) == part)
            {
                temp.erase(temp.length()-m);
            }
        }

        return temp;

    }
};