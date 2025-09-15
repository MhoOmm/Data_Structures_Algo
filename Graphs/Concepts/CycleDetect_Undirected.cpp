// dfs code

class Solution {
public:
    bool dfs(int node, int parent, vector<int> adj[], vector<bool> &visited) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if (dfs(neighbor, node, adj, visited))
                    return true;
            } else if (neighbor != parent) {
                return true; 
            }
        }

        return false;
    }

    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (dfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};


// bfs code

class Solution {
public:

    bool bfs(int node,int parent, vector<int>adj[],vector<bool>&visited)
    {
        queue<pair<int,int>>q;
        visited[node]=true;
        
        q.push({node,parent});
        
        while(!q.empty())
        {
            int node = q.front().first;
            int parent = q.front().second;
            
            q.pop();
            for(int i=0;i<adj[node].size();i++){
                
                if(adj[node][i]==parent)//skip maro
                {
                    continue;
                }
                
                if(visited[adj[node][i]])
                {
                    return true;
                }
                
                visited[adj[node][i]]=true;
                q.push({adj[node][i],node});
            }
            
        }
        return false;
    }
    bool isCycle(int V, vector<vector<int>>& edges) {
        
        vector<int> adj[V];
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u); 
        }

        vector<bool> visited(V, false);
        for (int i = 0; i < V; i++) {
            if (!visited[i]) {
                if (bfs(i, -1, adj, visited))
                    return true;
            }
        }

        return false;
    }
};
