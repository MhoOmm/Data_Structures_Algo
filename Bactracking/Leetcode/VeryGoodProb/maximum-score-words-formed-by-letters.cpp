class Solution {
public:
    int n ;
    int maxSc;
    void solve(int i,int currscore,vector<string>& words,vector<int>&freq,vector<int>&score){
        maxSc = max(maxSc,currscore);
        if(i>=n)
        {
            return;
        }

        int tempScore = 0;
        int j =0;
        vector<int>tempFreq = freq;
        while(j<words[i].length())
        {
            char ch = words[i][j];
            tempFreq[ch-'a']--;
            tempScore+=score[ch-'a'];

            if(tempFreq[ch-'a']<0) // word not present
            {
                break;
            }
            j++;
        }

        if(j==words[i].length()) // word can be taken
        {
            // take
            solve(i+1,tempScore+currscore,words,tempFreq,score);
        }

        // skip
        solve(i+1,currscore,words,freq,score);
    }
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        n = words.size();
        vector<int>freq(26,0);
        for(auto &ch:letters){
            freq[ch-'a']++;
        }

        maxSc = INT_MIN;
        solve(0,0,words,freq,score);
        return maxSc;
    }
};