// bfs for components -> counting the edges
// O(n+mlogn)
class Solution {
public:
    void bfs(unordered_map<int,vector<int>>&mp,vector<vector<int>>&adj,vector<bool>&visited,int src)
    {
        queue<int>q;
        q.push(src);
        mp[src].push_back(src);
        visited[src] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &neig:adj[node])
            {
                if(!visited[neig])
                {
                    visited[neig] = true;
                    mp[src].push_back(neig);
                    q.push(neig);
                }
            }
        }
    }
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count = 0;
        unordered_map<int,vector<int>>mp;
        vector<bool>visited(n,false);
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                bfs(mp,adj,visited,i);
            }
        }
        // now count the number of edges for each component
        // if it is n(n-1)/2 then it is complete.

        for(auto &it:mp){
            int node = it.first;
            auto vec = it.second;
            int edgeC = 0;
            for(int &num:vec)
            {
                edgeC += adj[num].size();
            }
            int nodeC = vec.size();
            if((edgeC/2) == (nodeC*(nodeC-1))/2)
            {
                count++;
            }
        }

        return count;
    }
};

// applying dsu - O((V+E)alpha(n))
class DSU {
public:
    vector<int> parent, rank;

    DSU(int n) {
        parent.resize(n);
        rank.assign(n,1);

        for(int i=0;i<n;i++)
            parent[i]=i;
    }

    int find(int x)
    {
        if(parent[x]==x)
            return x;

        return parent[x]=find(parent[x]);
    }

    void Union(int u,int v)
    {
        int parx=find(u);
        int pary=find(v);

        if(parx==pary) return;

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }
        else if(rank[parx]<rank[pary])
        {
            parent[parx] = pary;
        }
        else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
};

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {

        DSU dsu(n);

        for(auto &edge:edges){
            int u = edge[0];
            int v = edge[1];
            dsu.Union(u,v);
        }
        unordered_map<int,int> nodeC;
        unordered_map<int,int> edgeC;

        for(int i=0;i<n;i++)
            nodeC[dsu.find(i)]++;

        for(auto &edge:edges)
            edgeC[dsu.find(edge[0])]++;

        int ans=0;

        for(auto &[parent,nodes]:nodeC)
        {
            if(edgeC[parent]==nodes*(nodes-1)/2)
                ans++;
        }

        return ans;
    }
};