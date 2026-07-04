// bfs
class Solution {
public:
    int minScore(int n, vector<vector<int>>& roads) {
        vector<bool>visited(n+1,false);
        vector<vector<pair<int,int>>>adj(n+1);

        for(auto &edge:roads)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }

        queue<int>q;
        q.push(1);
        visited[1] = true;
        int result = INT_MAX;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &neigh:adj[node])
            {
                int ngbr = neigh.first;
                int wt = neigh.second;
                result = min(result,wt);
                if(!visited[ngbr])
                {
                    q.push(ngbr);
                    visited[ngbr] = true;
                } 
            }
        }

        return result;
    }
};

// dfs


class Solution {
public:
    void dfs(int curr,vector<vector<pair<int,int>>>&adj,vector<int>&visited,int &minwt)
    {
        visited[curr] = true;
        for(auto &neig:adj[curr]){
            int v   = neig.first;
            int wt  = neig.second;

            minwt = min(minwt,wt);

            if(!visited[v])
            {
                dfs(v,adj,visited,minwt);
            }
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj(n + 1);
        for(auto &edge:roads)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        vector<int>visited(n+1,false);
        int minwt = INT_MAX;
        dfs(1,adj,visited,minwt);

        return minwt;
    }
};

