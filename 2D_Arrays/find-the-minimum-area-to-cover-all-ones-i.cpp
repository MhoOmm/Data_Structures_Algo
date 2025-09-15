class Solution {
public:
    int minimumArea(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int maxL =  INT_MIN;
        int maxW= INT_MIN;
        int minL = INT_MAX;
        int minW = INT_MAX;

        for(int i = 0;i<n;i++)
        {
            for(int j =0 ;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    maxL = max(maxL,j);
                    maxW = max(maxW,i);
                    minL = min(minL,j);
                    minW = min(minW,i);
                }
            }
        }

        return (maxL-minL+1)*(maxW-minW+1);
    }
};