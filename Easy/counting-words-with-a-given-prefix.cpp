class Solution {
public:
    int prefixCount(vector<string>& words, string pref) {

        int n = words.size();
        int result = 0;

        for(auto &word:words)
        {
            string sub = word.substr(0,pref.length());
            if (sub == pref) result++;
        }
        return result;
    }
};