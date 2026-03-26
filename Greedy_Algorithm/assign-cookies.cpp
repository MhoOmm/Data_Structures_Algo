class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(begin(g),end(g));
        sort(begin(s),end(s));

        int maxGain = 0;
        int i =0;
        int j =0;

        while(i<g.size() && j<s.size())
        {
            if(s[j]>=g[i])
            {
                maxGain++;
                i++;
            }
            j++;
        }

        return maxGain;
    }
};