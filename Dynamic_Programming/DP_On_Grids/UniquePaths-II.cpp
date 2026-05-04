
//recur + memoization
class Solution {
public:
    int m,n;
    int t[101][101];
    int solve(int i,int j,vector<vector<int>>& grid)
    {
        if(i==m-1 && j==n-1)
        {
            return grid[i][j]==0;
        }

        if(i>=m || j>=n || i<0 || j<0 || grid[i][j]==1){
            return 0;
        }
        if(t[i][j]!=-1){
            return t[i][j];
        }

        // right
        int right = solve(i,j+1,grid);
        // down
        int down = solve(i+1,j,grid);

        return t[i][j] =  down+right;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,grid);
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