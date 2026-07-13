class Solution {
public:
    bool isSafe(int i,int j,int m,int n)
    {
        return (i>=0 && j>=0 && i<m && j<n);
    }
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int shortestPath(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();

        queue<tuple<int,int,int>>q;
        q.push({0,0,k});
        int steps = 0;
        vector<vector<vector<bool>>> visited(m, vector<vector<bool>>(n, vector<bool>(k+1,false)));
        visited[0][0][k] = true;
        while(!q.empty())
        {
            int size = q.size();

            while(size--)
            {
                auto [i,j,rem] = q.front();
                q.pop();

                if(i==m-1 && j==n-1)
                    return steps;

                for(auto &dir : directions)
                {
                    int ni = i + dir[0];
                    int nj = j + dir[1];

                    if(!isSafe(ni,nj,m,n))
                        continue;

                    if(grid[ni][nj] == 0)
                    {
                        if(!visited[ni][nj][rem])
                        {
                            visited[ni][nj][rem] = true;
                            q.push({ni,nj,rem});
                        }
                    }
                    else if(rem > 0)
                    {
                        if(!visited[ni][nj][rem-1])
                        {
                            visited[ni][nj][rem-1] = true;
                            q.push({ni,nj,rem-1});
                        }
                    }
                }
            }

            steps++;
        }
        return -1;
    }
};