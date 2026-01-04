class Solution {
public:
    int n, m;
    vector<vector<int>> directions{{0,1},{1,0},{0,-1},{-1,0}};

    int bfs(int i, int j, vector<vector<int>>& grid)
    {
        int sum = 0;
        queue<pair<int,int>> q;
        q.push({i, j});

        while(!q.empty())
        {
            auto [ti, tj] = q.front();
            q.pop();

            sum += grid[ti][tj]; 
            grid[ti][tj] = 0;      

            for(auto &dir : directions)
            {
                int ni = ti + dir[0];
                int nj = tj + dir[1];

                if(ni >= 0 && nj >= 0 && ni < n && nj < m && grid[ni][nj] != 0)
                {
                    q.push({ni, nj}); 
                }
            }
        }
        return sum;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        int result = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(grid[i][j] != 0)
                {
                    result = max(result, bfs(i, j, grid));
                }
            }
        }
        return result;
    }
};
