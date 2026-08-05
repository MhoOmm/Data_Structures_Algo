class Solution {
public:
    int rearrangeCharacters(string s, string target) {
        int n = s.length();
        vector<int>freqstr(26,0);
        vector<int>freqtar(26,0);
        for(auto &ch:s)
        {
            freqstr[ch-'a']++;
        }
        for(auto &ch:target)
        {
            freqtar[ch-'a']++;
        }
        int ans = INT_MAX;
        for(int i=0;i<26;i++){
            if(freqtar[i]>0)
            {
                ans = min(ans,freqstr[i]/freqtar[i]);
            }
        }
        return ans;
    }
};