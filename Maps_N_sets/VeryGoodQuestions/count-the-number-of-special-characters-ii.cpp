class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_map<char,pair<int,int>>mp; // A-> first occurence , number of occurence 
        // a -> last occurence, number of occurence
        int n = word.length();
        for(int i=0;i<n;i++)
        {
            // if small
            char ch = word[i];
            if(ch >= 'a' && ch <= 'z')
            {
                mp[ch].first = i;
                mp[ch].second ++;
            }
            // if big 
            if(ch >= 'A' && ch <= 'Z')
            {
                if(mp[ch].second==0)//not present till now
                    mp[ch].first = i;
                mp[ch].second ++;
            }
        }

        int count = 0;
        for(char ch='a';ch<='z';ch++)
        {
            char big = ch-32;
            if(mp[big].second>0 && mp[ch].second>0 && mp[ch].first < mp[big].first)
            {
                count++;
            }
        }

        return count;
    }
};