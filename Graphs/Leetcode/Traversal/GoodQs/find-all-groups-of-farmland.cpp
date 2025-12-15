class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    vector<vector<int>>result;
    int n,m;
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& land,int i,int j,int &r2 , int &c2)
    {
        land[i][j] = 0;
        q.push({i,j});
        while(!q.empty())
        {
            auto curr = q.front();
            q.pop();
            r2 = max(r2,curr.first);
            c2 = max(c2,curr.second);
            for(auto &dir:directions)
            {
                int ni = curr.first+dir[0];
                int nj = curr.second+dir[1];
                if(ni >= 0 && ni < n && nj >= 0 && nj < m && land[ni][nj] == 1) {
                    land[ni][nj] = 0; //visited
                    q.push({ni, nj});
                }
            }

        }
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {

        n = land.size();
        m = land[0].size();

        queue<pair<int,int>>q;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(land[i][j]==1)
                {
                    int r1 = i;
                    int c1 = j;
                    int r2 = -1;
                    int c2 = -1;
                    bfs(q,land,i,j,r2,c2);
                    result.push_back({r1,c1,r2,c2});
                }
            }
        }

        return result;
        
    }
};