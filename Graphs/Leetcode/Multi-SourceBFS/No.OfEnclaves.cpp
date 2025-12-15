class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int n,m;
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid){
        while(!q.empty())
        {
            int size = q.size(); 
            while(size--)
            {
                auto curr = q.front();
                q.pop();
                
                for(auto &dir:directions){
                    int ni = curr.first + dir[0];
                    int nj = curr.second + dir[1];

                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==1)
                    {
                        grid[ni][nj] = 0;
                        q.push({ni,nj});
                    }
                }
            }
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {

        n = grid.size();
        m = grid[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            if(grid[i][0]==1)
            {
                q.push({i,0});
                grid[i][0] = 0;
            }
            if(grid[i][m-1] == 1)
            {
                q.push({i,m-1});
                grid[i][m-1] = 0;
            }
        }
        for(int j=0;j<m;j++)
        {
            if(grid[0][j]==1)
            {
                q.push({0,j});
                grid[0][j] = 0;
            }
            if(grid[n-1][j]==1)
            {
                q.push({n-1,j});
                grid[n-1][j] = 0;
            }
        }

        if(q.empty())
        {
            return 0;
        }

        bfs(q,grid);
        int count = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1)
                {
                    count++;
                }
            }
        }

        return count;
        
    }
};