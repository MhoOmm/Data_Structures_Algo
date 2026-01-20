class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n=s.size();
        int i=0;
        int ans=0;
        int cost=0;
        for(int j=0;j<n;j++){
            int diff=abs(s[j]-t[j]);
            cost+=diff;
            while(cost>maxCost){
                int red=abs(s[i]-t[i]);
                cost-=red;
                i++;
            }
            ans=max(ans,j-i+1);
        }
        return ans;
    }
};