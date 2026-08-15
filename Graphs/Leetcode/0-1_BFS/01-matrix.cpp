class Solution {
public:
    typedef pair<int,int> pp;
    int m,n;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool isSafe(int i, int j)
    {
        return i >= 0 && i < m && j >= 0 && j < n;
    }
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        m = mat.size();
        n = mat[0].size();
        queue<pp>q;
        vector<vector<int>> dist(m, vector<int>(n, -1));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(mat[i][j]==0)
                {
                    dist[i][j] = 0;
                    q.push({i,j});
                }
            }
        }
        while(!q.empty())
        {
            auto [i,j] = q.front();
            q.pop();
            for(auto &dir:directions)
            {
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(isSafe(ni,nj))
                {
                    if(dist[ni][nj]==-1)
                    {
                        dist[ni][nj] = 1 + dist[i][j];
                        q.push({ni,nj});
                    }
                }
            }
        }
        return dist;
    }
};