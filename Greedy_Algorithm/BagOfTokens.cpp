class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        int n = tokens.size();
        int l =0;
        int r = n-1;

        sort(begin(tokens),end(tokens));

        int maxScore =0;
        int currScore =0;

        while(l<=r)
        {
            if(power>=tokens[l])
            {
                currScore++;
                maxScore = max(maxScore,currScore);
                power -= tokens[l];
                l++;
            }else if(currScore>=1){
                currScore--;
                power+=tokens[r];
                r--;
            }else{
                return maxScore;
            }
        }

        return maxScore;
    }
};