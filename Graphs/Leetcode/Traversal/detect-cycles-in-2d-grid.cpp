// O(m*n)
class Solution {
public:
    int m,n;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};

    bool bfs(int x,int y,vector<vector<char>>& grid,vector<vector<int>>&visited)
    {
        queue<tuple<int,int,int,int>>q;
        q.push({x,y,-1,-1});
        char ch = grid[x][y];
        visited[x][y] = 1;

        while(!q.empty())
        {
            auto [i,j,pi,pj] = q.front();
            q.pop();
            for(auto &dir:directions)
            {
                int ni = i+dir[0];
                int nj = j+dir[1];
                if(ni<0 || ni>=m || nj<0 || nj>=n)continue;
                if(grid[ni][nj]!=ch)
                {
                    continue;
                }

                if(visited[ni][nj] && !(ni==pi && nj==pj)){
                    // visited not parent
                    return true;
                }

                if(!visited[ni][nj] && grid[ni][nj]==ch)
                {
                    visited[ni][nj] = 1;
                    q.push({ni,nj,i,j});
                }
            }
        }
        return false;
    }
    bool containsCycle(vector<vector<char>>& grid) {
        m = grid.size();
        n = grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        // applying bfs for all nodes if anyone has a cycle return true
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++)
            {
                if(!visited[i][j])
                {
                    if(bfs(i,j,grid,visited))
                    {
                        return true;
                    }
                }
            }
        }
        return false;
    }
};