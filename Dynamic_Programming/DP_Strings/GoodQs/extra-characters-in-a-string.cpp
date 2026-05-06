// recurr + memoization
class Solution {
public:
    unordered_set<string>dict;
    int n;
    int t[51];
    int solve(int i,string &s)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        // take i as extra-character
        int take = 1+ solve(i+1,s);

        // not taking i as extra-character - we find wheter i..j is in the dict
        int skip = INT_MAX;
        string word = "";
        for(int j=i;j<n;j++)
        {
            word.push_back(s[j]);
            if(dict.find(word)!=dict.end())
            {
                skip = min(skip,solve(j+1,s));
            }
        }
        return t[i] = min(take,skip);
    }
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        memset(t,-1,sizeof(t));
        for(auto &word:dictionary)
        {
            dict.insert(word);
        }
        return solve(0,s);
    }
};

// bottom up solution
class Solution {
public:
    unordered_set<string>dict;
    int n;
    int minExtraChar(string s, vector<string>& dictionary) {
        n = s.length();
        for(auto &word:dictionary)
        {
            dict.insert(word);
        }
        vector<int>t(n+1,0);
        // same as top-down approach
        for(int i=n-1;i>=0;i--)
        {
            // take - taking it as extra character
            t[i] = 1 + t[i+1];//recursion calling ahead

            // skip 
            string word = "";
            for(int j=i;j<n;j++)
            {
                word.push_back(s[j]);
                if(dict.find(word)!=dict.end())
                {
                    t[i] = min(t[i],t[j+1]);
                }
            }
        }
        return t[0];
    }
};