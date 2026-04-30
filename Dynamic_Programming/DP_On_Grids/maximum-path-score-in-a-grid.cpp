class Solution {
public:
    int m,n;
    vector<vector<vector<int>>> t;
    int solve(vector<vector<int>>& grid,int i,int j,int cost,int k)
    {
        if(i>=m||j>=n||i<0||j<0)
        {
            return INT_MIN;
        }
        int nc = cost + (grid[i][j]>0);
        if(nc>k){
            return INT_MIN;
        }
        if(i==m-1 && j==n-1)
        {
            return grid[i][j];
        }

        if( t[i][j][nc]!=-1){
            return  t[i][j][nc];
        }

        int down = solve(grid,i+1,j,nc,k);
        int right = solve(grid,i,j+1,nc,k);
        int best = max(down,right);
        if(best==INT_MIN){
            return t[i][j][nc]=INT_MIN;
        }
        return  t[i][j][nc] = grid[i][j] + best;
    }
    int maxPathScore(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        t.assign(m,vector<vector<int>>(n,vector<int>(k+1,-1)));
        int ans = solve(grid,0,0,0,k);
        return ans==INT_MIN?-1:ans;
    }
};