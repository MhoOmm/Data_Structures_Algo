class Solution {
public:
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            adj[u].push_back({v,wt});
            adj[v].push_back({u,wt});
        }
        // let the shortest dist be w, then
        // for any edge to be in the shortest path a+x+b == w
        // where x is the dist from node1 to node2 and
        // a is the shortest dist from start to node1
        // b is the shortest dist from end to node2

        // djikstra from start node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq1;
        vector<int>dist1(n,INT_MAX);
        pq1.push({0,0});
        dist1[0] = 0;

        while(!pq1.empty())
        {
            auto [nodewt,node] = pq1.top();
            pq1.pop();

            if (nodewt > dist1[node])
                continue;

            for(auto &ngbr:adj[node])
            {
                int neig = ngbr.first;
                int neigwt = ngbr.second;

                if(neigwt+nodewt < dist1[neig])
                {
                    dist1[neig] = neigwt+nodewt;
                    pq1.push({neigwt+nodewt,neig});
                } 
            }
        }
        int shortestDist = dist1[n-1];
        // djikstra from end node
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq2;
        vector<int>dist2(n,INT_MAX);
        pq2.push({0,n-1});
        dist2[n-1] = 0;
        while(!pq2.empty())
        {
            auto [nodewt,node] = pq2.top();
            pq2.pop();

            if (nodewt > dist2[node])
                continue;

            for(auto &ngbr:adj[node])
            {
                int neig = ngbr.first;
                int neigwt = ngbr.second;

                if(neigwt+nodewt < dist2[neig])
                {
                    dist2[neig] = neigwt+nodewt;
                    pq2.push({neigwt+nodewt,neig});
                } 
            }
        }
        // returning the ans
        vector<bool>ans(edges.size(),false);
        for (int i = 0; i < edges.size(); i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            int x = edges[i][2];
            if ((dist1[u] != INT_MAX && dist2[v] != INT_MAX && dist1[u] + x + dist2[v] == shortestDist) ||(dist1[v] != INT_MAX && dist2[u] != INT_MAX && dist1[v] + x + dist2[u] == shortestDist)){
                ans[i] = true;
            }
        }
        return ans;
    }
};