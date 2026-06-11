class Solution {
public:
    int mod = 1e9+7;
    typedef long long ll;
    long long binaryExpo(ll a,ll b)
    {
        if(b==0)
        {
            return 1; // a^0 == 1
        }
        long long  half = binaryExpo(a,b/2);
        long long  ans  =( half*half)%mod;
        if(b%2==1)// odd
        {
            ans = (ans * a)%mod; 
        }

        return ans;
    }
    int dfs(int node,int parent,unordered_map<int,vector<int>>&adj)
    {
        int depth =0;
        for(auto &neig:adj[node])
        {
            if(neig!=parent)
            {
                depth = max(depth,dfs(neig,node,adj)+1);
            }
        }
        return depth;
    }
    int assignEdgeWeights(vector<vector<int>>& edges) {
        unordered_map<int,vector<int>>adj;
        int n = edges.size();

        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        int maxDepth = dfs(1,-1,adj);
        return binaryExpo(2,maxDepth-1);
    }
};