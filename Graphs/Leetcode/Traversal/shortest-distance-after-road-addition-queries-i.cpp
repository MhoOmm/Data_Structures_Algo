class Solution {
public:
    int bfs(int src,int dest,vector<vector<int>>&adj,int n)
    {
        queue<pair<int,int>>q;
        vector<bool>visited(n,false);
        q.push({src,0});
        visited[src] = true;
        while(!q.empty())
        {
            auto [node, dist] = q.front();
            q.pop();

            if(node == dest)
            {
                return dist;
            }
            for(auto &neig:adj[node])
            {
                if(!visited[neig])
                {
                    q.push({neig, dist + 1});
                    visited[neig] = true;
                }
            }
        }
        return -1;
    }
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++)
        {
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(auto &que:queries)
        {
            int u = que[0];
            int v = que[1];
            adj[u].push_back(v);
            ans.push_back(bfs(0,n-1,adj,n));
        }

        return ans;
    }
};