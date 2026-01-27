class Solution {
public:
    typedef pair<int,int> p;
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>> adj(n);

        for (auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            adj[u].push_back({v, wt});
            adj[v].push_back({u, 2 * wt});
        }

        priority_queue<p,vector<p>,greater<p>> pq;

        vector<int> dist(n, INT_MAX);
        dist[0] = 0;
        pq.push({0, 0});

        while (!pq.empty()) {
            auto [wt, node] = pq.top();
            pq.pop();

            if (node == n - 1) return wt;

            for (auto &neig : adj[node]) {
                int nd = neig.first;
                int ndwt = neig.second;

                if (wt + ndwt < dist[nd]) {
                    dist[nd] = wt + ndwt;
                    pq.push({dist[nd], nd});
                }
            }
        }

        return -1;
    }
};
