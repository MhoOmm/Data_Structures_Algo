class Solution {
public:
    int n,m;
    int mod = 1e9+7;
    vector<vector<vector<int>>>t;
    int solve(int i,int j,int sum,vector<vector<int>>& grid, int k){
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(i==m-1 && j==n-1)
        {
            return (sum+grid[i][j])%k==0?1:0;
        }

        if(t[i][j][sum]!=-1)
        {
            return t[i][j][sum];
        }

        int down = solve(i+1,j,(sum+grid[i][j])%k,grid,k);
        int right = solve(i,j+1,(sum+grid[i][j])%k,grid,k);

        return t[i][j][sum] = (down+right)%mod;
    }
    int numberOfPaths(vector<vector<int>>& grid, int k) {
        m = grid.size();
        n = grid[0].size();
        t.assign(m,vector<vector<int>>(n,vector<int>(k,-1)));
        return solve(0,0,0,grid,k);
    }
};