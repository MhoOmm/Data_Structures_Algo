// User function Template for C++

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        vector<int>dist(V,1e8);
        dist[src] = 0;
        for(int count = 1;count<=V-1;count++)
        {
            for(auto &edge:edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    dist[v] = dist[u]+wt;
                }
                
            }
        }
        // Relaxing once more:If cycle present then it keeps on relaxing
        // So break
        for(auto &edge:edges)
            {
                int u = edge[0];
                int v = edge[1];
                int wt = edge[2];
                if(dist[u]!=1e8 && dist[u]+wt<dist[v]){
                    return {-1};
                }
                
            }
        
        return dist;
        
    }
};
