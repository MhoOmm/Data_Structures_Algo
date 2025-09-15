class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        int count=0;
        int n=words.size();
        unordered_map<string,int>mp;
        for(auto &sr:words)
        {
            string rev=sr;
            swap(rev[0],rev[1]);
            if(mp[rev]>0)
            {
                count+=4;
                mp[rev]--;
            }
            else{
                mp[sr]++;
            }
        }
        //equal character words
        for(auto &it:mp)
        {
            string word=it.first;
            int co=it.second;
            if(word[0]==word[1] && co>0)
            {
                count+=2;
                break;
            }

        }
        return count;
    }
};