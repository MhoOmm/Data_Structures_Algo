// using priority Queue
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        
        vector<pair<int, int>> adj[V];

    
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w}); 
            adj[v].push_back({u, w});
        }
        
        vector<int>result(V,INT_MAX);
        result[src]=0;
        pq.push({0,src});
        
        while (!pq.empty())
        {
            int d=pq.top().first;
            int node= pq.top().second;
            pq.pop();
            
            for(auto &vec : adj[node])
            {
                int neig = vec.first;
                int dist = vec.second;
                if(d+dist < result[neig])
                {
                    result[neig]=d+dist;
                    pq.push({d+dist,neig});
                }
            }
        }
        
        return result;
        
    }
};

// Using Set: we can erase the element we dont want to reduce the extra steps 
class Solution {
  public:
    vector<int> dijkstra(int V, vector<vector<int>> &edges, int src) {
        // Code here

        vector<pair<int, int>> adj[V];
        set<pair<int,int>>st;
    
        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            adj[u].push_back({v, w}); 
            adj[v].push_back({u, w});
        }
        
        vector<int>result(V,INT_MAX);
        result[src]=0;
        st.insert({0,src});
        
        while (!st.empty())
        {
            auto &it = *st.begin();
            int d = it.first;
            int node= it.second;
            
            st.erase(it);
            
            for(auto &vec : adj[node])
            {
                int neig = vec.first;
                int dist = vec.second;
                if(d+dist < result[neig])
                {
                    if(result[node]!=INT_MAX)
                    {
                        st.erase({result[node],node});
                    }
                    result[neig]=d+dist;
                    st.insert({d+dist,neig});
                }
            }
        }
        
        return result;
        
    }
};


