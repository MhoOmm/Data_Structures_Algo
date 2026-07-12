class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int n;
    void bfs(int i,int j,vector<vector<int>>& grid,set<pair<int,int>>&visited)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        visited.insert({i,j});

        while(!q.empty())
        {
            auto [x,y] = q.front();
            q.pop();
            for(auto &dir:directions)
            {
                int ni = x+dir[0];
                int nj = y+dir[1];
                if(ni>=0 && nj>=0 && ni<n && nj<n && grid[ni][nj]==1 && visited.find({ni, nj}) == visited.end())
                {
                    visited.insert({ni,nj});
                    q.push({ni,nj});
                }
            }
        }
    }

    int bfsans(vector<vector<int>>& grid,set<pair<int,int>>&visited)
    {
        int count = 0;
        queue<pair<int,int>>q;
        for(auto &pair:visited)
        {
            q.push({pair});
        }
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                pair<int,int>p = q.front();
                q.pop();
                for(auto &dir:directions)
                {
                    int ni = p.first + dir[0];
                    int nj = p.second + dir[1];
                    if(ni>=0 && nj>=0 && ni<n && nj<n && visited.find({ni,nj}) == visited.end())
                    {
                        if(grid[ni][nj]==1)
                        {
                            return count;
                        }
                        visited.insert({ni,nj});
                        q.push({ni,nj});
                    }
                }
            }
            count++;
        }

        return count;
    }
    int shortestBridge(vector<vector<int>>& grid) {
       n = grid.size();
       set<pair<int,int>>visited;
       for(int i=0;i<n;i++)
       {
        for(int j=0;j<n;j++){
            if(grid[i][j]==1)
            {
                bfs(i,j,grid,visited);
                return bfsans(grid,visited);
            }
        }
       } 
       return -1;
    }
};