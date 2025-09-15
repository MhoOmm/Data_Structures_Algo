class Solution {
  public:
    int cutRod(vector<int> &price) {
        // code here
        int n=price.size();
        vector<int>length(n);
        for(int i=0;i<n;i++)
        {
            length[i]=i+1;
        }
        int target=n;
        
        vector<vector<int>>t(n+1,vector<int>(target+1,0));
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                    if(length[i-1]<=j)
                    {
                        int take=price[i-1]+t[i][j-length[i-1]];
                        int skip=t[i-1][j];
                        t[i][j]=max(take,skip);
                    }else{
                        t[i][j]=t[i-1][j];
                    }
            }
        }
        
        return t[n][target];
        
    }
};
