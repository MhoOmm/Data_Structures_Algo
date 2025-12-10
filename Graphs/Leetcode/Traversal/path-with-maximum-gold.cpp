class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    int m,n;
    int solve(int i,int j ,vector<vector<int>>& grid)
    {
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]==0)
        {
            return 0;
        }
        int ogvalue = grid[i][j];
        grid[i][j] = 0;//update value

        int maxval = 0;

        for(auto &dir:directions)
        {
            int newi = i + dir[0];
            int newj = j + dir[1];

            maxval = max(maxval,solve(newi,newj,grid));
        }
        grid[i][j] = ogvalue;
        return ogvalue + maxval;
    }
    int getMaximumGold(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        int result = 0;
        for(int i =0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                if(grid[i][j]!=0)
                {
                    result = max(result,solve(i,j,grid));
                }
            }
        }
        

        return result;
    }
};