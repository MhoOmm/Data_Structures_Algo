class Solution {
  public:
    int knapSack(vector<int>& val, vector<int>& wt, int capacity) {
        // code here
           int n=val.size();
           vector<vector<int>>t(n+1,vector<int>(capacity+1,0));
           
           for(int i=1;i<=n;i++)
           {
               for(int j=1;j<=capacity;j++)
                {
                    if(wt[i-1]<=j)
                    {
                        int take=val[i-1]+t[i][j-wt[i-1]];
                        int skip=t[i-1][j];
                        t[i][j]=max(take,skip);
                    }else{
                        t[i][j]=t[i-1][j];
                    }
                }
           }
           return t[n][capacity];
    }
};