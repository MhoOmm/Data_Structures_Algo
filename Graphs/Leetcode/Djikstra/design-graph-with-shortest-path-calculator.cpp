//  easy question simple implementation
class Graph {
public:
    typedef pair<int,int> pp;
    unordered_map<int,vector<pair<int,int>>>adj;
    int N ;
    Graph(int n, vector<vector<int>>& edges) {
        N = n;
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({wt,v});
        }
    }
    
    void addEdge(vector<int> edge) {
        int u = edge[0];
        int v = edge[1];
        int wt = edge[2];

        adj[u].push_back({wt,v});
    }
    
    int shortestPath(int node1, int node2) {
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        int n = adj.size();
        vector<int>dist(N,INT_MAX);
        dist[node1] = 0;
        pq.push({0,node1});

        while(!pq.empty()){
            int nodewt = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (nodewt > dist[node])continue;
            
            for(auto &neig:adj[node])
            {
                int ngbwt = neig.first;
                int ngbn = neig.second;
                if( nodewt+ngbwt < dist[ngbn])// distance from src shorter than
                {
                    dist[ngbn] =  nodewt+ngbwt;
                    pq.push({ nodewt+ngbwt,ngbn});
                }
            }
        }
        return dist[node2]==INT_MAX?-1:dist[node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */