class Solution {
public:
    int n;
    vector<string>result;
    unordered_set<string>st;
    void solve(int i,string &curr,string &s){
        if(i>=n)
        {
            result.push_back(curr);
            return;
        }

        for(int length =1;i+length<=n;length++)
        {
            string temp = s.substr(i,length);
            if(st.find(temp)!=st.end())
            {
                string tillnow = curr;
                if(!curr.empty())
                {
                    curr+=" ";
                }
                curr += temp;
                solve(i+length,curr,s);
                curr = tillnow;
            }
        }
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        n = s.length();

        for(auto &word:wordDict)
        {
            st.insert(word);
        } 

        string curr = ""; 
        solve(0,curr,s);
        return result; 
    }
};