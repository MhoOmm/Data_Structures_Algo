// BFS CODE
class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int src, int dest) {
        vector<vector<int>>adj(n);
        vector<bool>visited(n,false);
        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        queue<int>q;
        q.push(src);
        visited[src]= true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            
            if (node == dest) return true;

            for(auto &neig:adj[node]){
                if(!visited[neig]){
                    visited[neig]= true;
                    q.push(neig);
                }
            }
        }

        return visited[dest];
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