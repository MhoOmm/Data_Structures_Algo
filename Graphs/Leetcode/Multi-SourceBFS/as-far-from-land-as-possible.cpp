class Solution {
public:
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int n,m;
    void bfs(queue<pair<int,int>>&q,vector<vector<int>>& grid,int &count){
        while(!q.empty())
        {
            int size=q.size();
            while(size--){
                auto curr = q.front();
                q.pop();
                int i = curr.first;
                int j = curr.second;
                for(auto &dir:directions)
                {
                    int ni = i+dir[0];
                    int nj = j+dir[1];

                    if(ni>=0 && nj>=0 && ni<n && nj<m && grid[ni][nj]==0)
                    {
                        q.push({ni,nj});
                        grid[ni][nj]=1;
                    }
                }
            }
            count++;
        }
    }
    int maxDistance(vector<vector<int>>& grid) {
        n = grid.size();
        m = grid[0].size();

        queue<pair<int,int>>q;
        for(int i=0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]==1)
                {
                    q.push({i,j});
                }
            }
        }
        if(q.empty() || q.size() == n*m) return -1;
        int count =0;

        bfs(q,grid,count);
        return count-1; 
    }
};