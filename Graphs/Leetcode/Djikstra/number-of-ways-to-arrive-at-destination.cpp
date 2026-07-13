class Solution {
public:
    typedef pair<long long,int> pp;
    const int MOD = 1e9 + 7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:roads)
        {
            int u = edge[0];
            int v = edge[1];
            int time = edge[2];
            adj[u].push_back({v,time});
            adj[v].push_back({u,time});
        }
        vector<int>countW(n,0);
        vector<long long>dist(n,LLONG_MAX);
        priority_queue<pp, vector<pp>, greater<pp>>pq;
        dist[0] = 0;
        countW[0] = 1;
        pq.push({0,0}) ; // time, node

        while(!pq.empty()){
            long long time = pq.top().first;
            int node = pq.top().second;
            pq.pop();

            if (time > dist[node])continue;

            for(auto &ngbr : adj[node]){
                long long ngwt = ngbr.second;
                int neig = ngbr.first;

                if(time+ ngwt < dist[neig])
                {
                    dist[neig] = time+ngwt;
                    pq.push({dist[neig],neig});
                    countW[neig] = countW[node];
                }
                else if(time+ngwt == dist[neig])
                {
                    // we have already passed this once 
                    countW[neig] = (countW[neig] + countW[node])%MOD;
                }
            }
        }

        return countW[n-1];
    }
};