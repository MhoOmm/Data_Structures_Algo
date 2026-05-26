// dfs solutions
// solve(i,j) -> will return the number of increasing paths ENDING on grid[i][j]
class Solution {
public:
    vector<vector<int>>directions{{0,-1},{-1,0},{0,1},{1,0}};
    int m,n;
    int mod = 1e9+7;
    int t[1001][1001];
    int solve(int i,int j,vector<vector<int>>&grid)
    {
        long long seqend = 1;// everybody has one sequence ending at themselves
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        for(auto &dir:directions)
        {
            int ni = i+dir[0];
            int nj = j+dir[1];
            if(ni>=0  && nj>=0 && ni<m && nj<n && grid[ni][nj]<grid[i][j])
            {
                seqend = (seqend + solve(ni,nj,grid))%mod;
            }
        }
        return t[i][j] = seqend;
    }
    int countPaths(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        memset(t,-1,sizeof(t));
        int count = 0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                count= (count + solve(i,j,grid))%mod;
            }
        }

        return count;
    }
};