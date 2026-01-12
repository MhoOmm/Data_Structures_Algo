class Solution {
public:
    int count;
    void dfs(int u,int &count,vector<vector<pair<int,int>>>&adj,vector<bool>&visited)
    {
        visited[u] = true;
        for(auto &neig:adj[u])
        {
            int v = neig.first ;
            int parity = neig.second;
            if(!visited[v]){
                if(parity==1)count++;
                dfs(v,count,adj,visited);
            }
        }
    }
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:connections){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back({v,1});
            adj[v].push_back({u,0});
        }

        count=0;
        vector<bool>visited(n,false);
        dfs(0,count,adj,visited);

        return count;
    }
};