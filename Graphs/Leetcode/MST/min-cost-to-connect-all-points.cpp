// prim's algorithm

class Solution {
public:
    typedef pair<int,int>P;

    int minSt(vector<vector<P>>&adj,int V)
    {
        priority_queue<P,vector<P>,greater<P>>pq;
        pq.push({0,0});

        vector<bool>visited(V,false);

        int ans = 0;

        while(!pq.empty())
        {
            int wt = pq.top().first;
            int node =pq.top().second;
            pq.pop();

            if(visited[node]==true)continue;

            visited[node]=true;
            ans+=wt;
            for(auto &nod:adj[node])
            {
                int nn_wt = nod.first;
                int nn = nod.second;

                pq.push({nn_wt,nn});
            }
        }
        return ans;
    }

    int minCostConnectPoints(vector<vector<int>>& points) {

        int V = points.size();
        vector<vector<P>>adj(V);

        for(int i =0;i<V;i++)
        {
            for(int j=i+1;j<V;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dist = abs(x2-x1) + abs(y2-y1);

                adj[i].push_back({dist,j});
                adj[j].push_back({dist,i});
            }
        }

        return minSt(adj,V);

    }
};


// Kruskal's Algorithm

class Solution {
public:

    vector<int>parent;
    vector<int>rank;

    int find(int x)
    {
        if(x==parent[x])
        {
            return x;
        }

        return parent[x] = find(parent[x]);
    }

    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);

        if(parx==pary)return;

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }else if(rank[pary]>rank[parx]){
            parent[parx] = pary;
        }
        else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int V = points.size();
        parent.resize(V);
        rank.resize(V,0);

        for(int i = 0;i<V;i++)
        {
            parent[i]=i;
        }

        vector<vector<int>>edges;
        for(int i =0;i<V;i++)
        {
            for( int j=i+1;j<V;j++)
            {
                int x1 = points[i][0];
                int y1 = points[i][1];
                int x2 = points[j][0];
                int y2 = points[j][1];
                int d = abs(x2-x1) + abs(y2-y1);
                edges.push_back({i,j,d});
            }
        }


        sort(begin(edges),end(edges),[](auto &edg1, auto &edg2){
            return edg1[2]<edg2[2];
        });

        int sum= 0;
        for(auto &edge:edges)
        {
            int x = edge[0];
            int y = edge[1];
            int wt  = edge[2];

            int j = find(x);
            int k = find(y);

            if(j==k)continue;
            else{
                sum+=wt;
                Union(x,y);
            }
        }

        return sum;
    }
};