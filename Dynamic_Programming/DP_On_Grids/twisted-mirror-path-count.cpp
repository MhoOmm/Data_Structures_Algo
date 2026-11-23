class Solution {
public:
    int m, n;
    int mod = 1e9 + 7;
    // com = 0 -> Came from up
    // com = 1 -> Came from left
    int t[501][501][2];
    int solve(int i, int j, int com, vector<vector<int>>& grid)
    {
        if(i < 0 || j < 0 || i >= m || j >= n)
            return t[i][j][com] = 0;

        if(i == m-1 && j == n-1)
            return t[i][j][com] = 1;

        if(t[i][j][com]!=-1)
        {
            return t[i][j][com];
        }
        if(grid[i][j] == 1)
        {
            if(com == 0){
                // Came from up, turn right
                return t[i][j][com] = solve(i, j+1, 1, grid);
            }
            else{
                // Came from left, turn down
                return t[i][j][com] = solve(i+1, j, 0, grid);
            }
        }
        int total = 0;
        // Right
        total = (total+solve(i,j+1,1,grid))%mod;
        // Down
        total = (total+solve(i+1,j,0,grid))%mod;
        return t[i][j][com] = total;
    }

    int uniquePaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        return solve(0,0,0,grid);
    }
};