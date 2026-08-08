class Solution {
public:
    vector<int>rank;
    bool compare(string &word1,string &word2)
    {
        int n = min(word1.length(),word2.length());
        for(int i=0;i<n;i++)
        {
            // order not good
            if(rank[word1[i]-'a'] > rank[word2[i]-'a'])
            {
                return false;
            }
            // order is good
            else if(rank[word1[i]-'a'] < rank[word2[i]-'a'])
            {
                return true;
            }
        }
        // if both the words have common elements till n then shorter will come first
        return word1.length() <= word2.length();
    }
    bool isAlienSorted(vector<string>& words, string order) {
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            rank[order[i]-'a'] = i;
        }
        for(int i=1;i<words.size();i++)
        {
            if(compare(words[i-1],words[i])==false)
            {
                return false;
            }
        }
        return true;
    }
};