class Solution {
public:
    unordered_map<string,bool>mp;
    bool solve(string s1,string s2)
    {
        if(s1==s2)
        {
            return true;
        }
        if(s1.length()!=s2.length())
        {
            return false;
        }

        string key = s1+"_"+s2;
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        bool result= false;
        int n = s1.length();
        for(int i=1;i<s1.length();i++)
        {
            // swap
            bool swap =solve(s1.substr(0, i), s2.substr(n-i,i))&&solve(s1.substr(i,n-i),s2.substr(0,n-i));
            // no swap
            bool no_swap =solve(s1.substr(0,i),s2.substr(0,i))&&solve(s1.substr(i,n-i),s2.substr(i,n-i));
            if(no_swap||swap){
                result = true;
                break;
            }
        }
        return mp[key] = result;
    }
    bool isScramble(string s1, string s2) {
        return solve(s1,s2);
    }
};