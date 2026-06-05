// bfs
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        int m = edges.size();
        if(source == destination)
        {
            return true;
        }
        vector<vector<int>>adj(n);
        for(int i=0;i<m;i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        queue<int>q;
        vector<bool>visited(n,false);
        q.push(source);
        visited[source] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &neig:adj[node])
            {
                // if one of the neighbours is destination
                if(neig==destination)
                {
                    return true;
                }
                if(!visited[neig])
                {
                    visited[neig] = true;
                    q.push(neig);
                }
            }
        }

        return false;
    }
};

// DFS CODE
class Solution {
public:
    bool dfs(int curr,int dest,vector<vector<int>>&adj,vector<bool>&visited){
        if(curr == dest) return true;

        if(visited[curr])return false; //already visited

        visited[curr ] = true;

        for(auto &node:adj[curr]){
            if(dfs(node,dest,adj,visited)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        return dfs(src,dest,adj,visited);
    }
};