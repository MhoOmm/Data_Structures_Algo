// not djikstra but using priority queue to bolna padega
class Solution {
public:
    typedef pair<int,pair<int,int>> P;
    vector<vector<int>> directions{{0,1},{0,-1},{1,0},{-1,0}};
    int minimumTime(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        // -1 case
        if(grid[1][0] >1 && grid[0][1]>1)
        {
            return -1;
        }
        priority_queue<P,vector<P>,greater<P>>pq;
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        vector<vector<bool>>visited(n,vector<bool>(m,false));

        pq.push({grid[0][0],{0,0}});
        result[0][0]=0;

        while(!pq.empty())
        {
            int time = pq.top().first;
            int row = pq.top().second.first;
            int col = pq.top().second.second;
            pq.pop();

            if(row==n-1 && col==m-1)
            {
                return result[n-1][m-1];
            }

            if(visited[row][col])continue;

            visited[row][col]=true;
            for(auto &dir:directions)
            {
                int i = row+dir[0];
                int j = col+dir[1];

                if(i<0 || j<0 || i>=n || j>=m)
                {
                    continue;
                } 
                
                // three case
                if(grid[i][j]<=time+1){
                    pq.push({time+1,{i,j}});
                    result[i][j] = time +1;
                }
                else if((grid[i][j]-time)%2==0)
                {
                    pq.push({grid[i][j]+1,{i,j}});
                    result[i][j] = grid[i][j]+1;
                }
                else{
                    pq.push({grid[i][j],{i,j}});
                    result[i][j] = grid[i][j];
                }
            }

        }

        return -1;
    }
};