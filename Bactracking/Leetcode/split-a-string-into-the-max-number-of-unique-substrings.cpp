class Solution {
public:
    int maxval ;
    void solve(int i,int curr,unordered_set<string>&st,string &s)
    {
        if(i>=s.length())
        {
            maxval = max(maxval,curr);
            return;
        }
        for(int j = i;j<s.length();j++)
        {
            string temp = s.substr(i,j-i+1);
            if(st.find(temp)==st.end())//not present
            {
                st.insert(temp);
                solve(j+1,curr+1,st,s);
                st.erase(temp);
            }
        }
    }
    int maxUniqueSplit(string s) {
        int n = s.length();
        maxval = 0 ;
        unordered_set<string>st;
        solve(0,0,st,s);
        return maxval ;
    }
};