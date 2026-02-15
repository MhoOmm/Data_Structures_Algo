class Solution {
public:
    int maxScore(vector<int>& cards, int k) {
        int n = cards.size();
        int leftSum =0;
        for(int i=0;i<k;i++){
            leftSum+=cards[i];
        }
        
        int rightSum=0;
        int l = n-1;
        int mxPoint = leftSum; 
        for(int i=k-1;i>=0;i--)
        {
            leftSum -= cards[i];
            rightSum += cards[l];
            l--;

            mxPoint= max(mxPoint,leftSum+rightSum);
        }
        return mxPoint;
    }
};