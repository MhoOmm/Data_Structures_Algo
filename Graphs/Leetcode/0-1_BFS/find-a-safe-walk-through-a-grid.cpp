class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int m = grid.size();
        int n = grid[0].size();

        deque<pair<int,int>>dq;
        vector<vector<int>>dist(m,vector<int>(n,INT_MAX));
        dq.push_front({0,0});
        dist[0][0] = grid[0][0];
        while(!dq.empty())
        {
            auto [i,j] = dq.front();
            dq.pop_front();
            for(auto &dir:directions)
            {
                int ni = i+dir[0];
                int nj = j+dir[1];
                
                if(ni>=0 && nj>=0 && ni<m && nj<n && (grid[ni][nj]+dist[i][j]) < dist[ni][nj] )
                {
                    int wt = grid[ni][nj];
                    dist[ni][nj] = wt+dist[i][j];
                    if(grid[ni][nj]==0)
                    {
                        dq.push_front({ni,nj});
                    }else{
                        dq.push_back({ni,nj});
                    }
                }
            }
        }
        int minH = dist[m-1][n-1];
        return (health-minH)>=1;
    }
};