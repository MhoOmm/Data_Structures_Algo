class Solution {
public:
    int nobs;
    int m,n;
    int count;
    vector<vector<int>>directions={{0,1},{0,-1},{1,0},{-1,0}};
    void backtrack(vector<vector<int>>& grid,int i,int j,int curr)
    {
        if(i>=n||i<0||j>=m||j<0||grid[i][j]==-1)
        {
            return;
        }
        if(grid[i][j]==2)
        {
            if(curr==nobs+1)
            {
                count++;
            }
            return;
        }

        for(auto &dir:directions)
        {
            int ni = i+dir[0];
            int nj = j+dir[1];

            int temp = grid[i][j];
            grid[i][j] = -1;
            backtrack(grid,ni,nj,curr+1);
            grid[i][j] = temp;
        }
    }
    int uniquePathsIII(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();
        int x=0,y =0;

        nobs = 0;
        count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==0)
                {
                    nobs++;
                }
                else if(grid[i][j]==1){
                    x = i;
                    y = j;
                }
            }
        }

        backtrack(grid,x,y,0);

        return count;
    }
};