class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int m,n;
    void bfs(int i,int j,vector<vector<char>>& grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        grid[i][j]='2';
        while(!q.empty())
        {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();

            for(auto &dir:directions)
            {
                int ni = x+dir[0];
                int nj = y+dir[1];
                if(ni>=0 && nj>=0 && ni<m && nj<n && grid[ni][nj]=='1')
                {
                    grid[ni][nj] = '2';
                    q.push({ni,nj});
                }
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int count =0;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(grid[i][j]=='1')
                {
                    bfs(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};