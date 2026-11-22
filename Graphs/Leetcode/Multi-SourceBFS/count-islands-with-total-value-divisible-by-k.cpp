class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    long long bfs(int i, int j, vector<vector<int>>& grid)
{
    long long sum = grid[i][j];
    queue<pair<int,int>> q;

    q.push({i,j});
    grid[i][j] = 0;

    while(!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        for(auto &dir : directions)
        {
            int ni = x + dir[0];
            int nj = y + dir[1];

            if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] != 0)
            {
                sum += grid[ni][nj];
                grid[ni][nj] = 0;
                q.push({ni,nj});
            }
        }
    }

    return sum;
}
    int countIslands(vector<vector<int>>& grid, int k) {
        n = grid.size();
        m = grid[0].size();
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++){
                if(grid[i][j]!=0)
                {
                    long long sum = bfs(i,j,grid);
                    if(sum%k==0)
                    {
                        count++;
                    }
                }
            }
        }
        return count;
    }
};