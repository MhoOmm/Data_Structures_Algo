class Solution {
public:
    int n;
    int t[301][11];
    int solve(vector<int>&jd,int d,int i){
        if(d==1)
        {
            return *max_element(jd.begin()+i,jd.end());
        }
        if(t[i][d]!=-1)
        {
            return t[i][d];
        }
        int maxEle = jd[i];
        int finResult = INT_MAX;
        for(int j=i;j<=n-d;j++)// loop will run n-d times only
        {
            maxEle = max(maxEle,jd[j]);
            int result = maxEle + solve(jd,d-1,j+1);
            finResult = min(finResult,result);
        }
        return t[i][d] = finResult;
    }
    int minDifficulty(vector<int>& jd, int d) {
        n = jd.size();
        if(n<d)return -1; // ho hi nhi sakta ek din khali chal jayega
        memset(t,-1,sizeof(t));
        return solve(jd,d,0);
    }
};