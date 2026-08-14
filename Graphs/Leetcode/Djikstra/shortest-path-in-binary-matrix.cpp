class Solution {
public:
    int n,m;
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>>directions{{0,1},{0,-1},{-1,0},{1,0},{1,1},{-1,1},{1,-1},{-1,-1}};
    bool isSafe(int i,int j)
    {
        return (i>=0 && j>=0 && i<n && j<m);
    }
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();
        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)return -1;
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({1,{0,0}});
        dist[0][0] = 1;
        grid[0][0] = 1;
        
        while(!pq.empty())
        {
            int di = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            for(auto &dir:directions)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];
                
                if(isSafe(ni,nj) && grid[ni][nj]==0)
                {
                    // 1 added coz of one cost of travelling to the next box
                    if(1 + di < dist[ni][nj] )
                    {
                        dist[ni][nj] = di+1;
                        grid[ni][nj] = 1;
                        pq.push({di+1,{ni,nj}});
                    }
                }
            }
        }

        return dist[n-1][m-1]==INT_MAX ? -1:dist[n-1][m-1];
    }
};