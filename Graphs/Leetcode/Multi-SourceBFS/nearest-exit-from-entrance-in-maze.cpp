class Solution {
public:
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int,int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';
        int step =0;
        while(!q.empty()){
            int size = q.size();
            while(size--)
            {
                int i = q.front().first;
                int j = q.front().second;
                if(!(i==entrance[0] && j==entrance[1]) && 
                (i==0 || j==0 || i==n-1 || j==m-1 ))
                {
                    return step;
                }
                q.pop();
                for(auto &dir:directions)
                {
                    int ni = i+dir[0];
                    int nj = j+dir[1];
                    if(ni>=0 && nj>=0 && ni<n && nj<m && maze[ni][nj]=='.')
                    {
                        maze[ni][nj] = '+';
                        q.push({ni,nj});
                    }
                }
            }
            step++;
        }
        return -1;
    }
};