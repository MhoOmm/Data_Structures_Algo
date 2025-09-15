
//recur + memoization
class Solution {
    public:
    
        int m,n;
    
        int t[101][101];
    
        int solve(int i,int j,vector<vector<int>>& obs)
        {
            if(i==m-1 && j==n-1 && obs[m-1][n-1]!=1)
            {
                return 1;
            }
            if(i<0||i>=m||j>=n||j<0)
            {
                return 0;
            }
            if(obs[i][j]==1)
            {
                return 0;
            }
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
    
            int right=solve(i,j+1,obs);
            int down=solve(i+1,j,obs);
    
            return t[i][j]=right+down;
    
        }
        int uniquePathsWithObstacles(vector<vector<int>>& obs) {
            m = obs.size();
            n = obs[0].size();
    
            memset(t,-1,sizeof(t));
    
            return solve(0,0,obs);
    
            
        }
    };

//bottom up 

class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obs) {
    
            int m=obs.size();
            int n=obs[0].size();
            vector<vector<int>>t(m+1,vector<int>(n+1,-1));
    
            for(int i=0;i<m;i++)
            {
                if(i>0 && obs[i-1][0]==1)
                {
                    obs[i][0]=1;
                    t[i][0]=0;
                }
                else if(obs[i][0]==1)
                {
                    t[i][0]=0;
                }
                else{
                    t[i][0]=1;
                }
            }
            for(int j=0;j<n;j++)
            {
                if(j>=1 && obs[0][j-1]==1)
                {
                    obs[0][j]=1;
                    t[0][j]=0;
                }
                else if(obs[0][j]==1){
    
                    t[0][j]=0;
    
                }
                else{
                    t[0][j]=1;
                }
            }
    
            for(int i=1;i<m;i++)
            {
                for(int j=1;j<n;j++)
                {
                    if(obs[i][j]==1)
                    {
                        t[i][j]=0;//no way to reach
                    }
                    else{
    
                        t[i][j]=t[i-1][j]+t[i][j-1];
    
                    }
                }
            }
    
    
            return t[m-1][n-1];
            
        }
    };