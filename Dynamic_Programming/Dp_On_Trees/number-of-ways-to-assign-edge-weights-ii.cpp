class Solution {
public:
    int rows,cols;
    vector<int>depthNode;
    vector<vector<int>>ancestor;
    int mod = 1e9+7;
    // to make the ancestor table
    void fillTable()
    {
        for(int j=1;j<cols;j++)
        {
            for(int node=0;node<rows;node++)
            {
                if(ancestor[node][j-1]!=-1)
                {
                    ancestor[node][j] = ancestor[ancestor[node][j-1]][j-1];
                }
            }
        }
    }
    // dfs code
    void dfs(int node,int parent,vector<vector<int>>&adj,int depth)
    {
        depthNode[node] = depth;
        ancestor[node][0] = parent;
        depth++;
        for(auto &neig:adj[node])
        {
            if(neig!=parent)
            {
                dfs(neig,node,adj,depth);
            }
        }
    }
    // find kth ancestor
    int findKth(int node,int k)
    {
        if(node == -1) return -1;
        for(int j=0;j<cols;j++)
        {
            if(k & (1<<j)) // jth bit set for k
            {
                node = ancestor[node][j];
                if(node==-1)
                {
                    return -1;
                }
            }
        }
        return node;
    }
    // find lca of two nodes
    int findLCA(int u,int v)
    {
        int du = depthNode[u];
        int dv = depthNode[v];
        if(du<dv)
        {
            swap(u,v);
            swap(du,dv);
        }
        if(du!=dv)
        {
            int diff = du-dv;
            u = findKth(u,diff);
        }
        if(u == v) return u;

        for(int j=cols-1;j>=0;j--)
        {
            if(ancestor[u][j]==-1)
            {
                continue;
            }
            // after they are at the same level
            if(ancestor[u][j]!=ancestor[v][j])
            {
                u = ancestor[u][j];
                v = ancestor[v][j];
            }
        }
        return ancestor[u][0];
    }

    vector<int> assignEdgeWeights(vector<vector<int>>& edges, vector<vector<int>>& queries) {
        int n = edges.size()+1;
        rows = n;
        cols = log2(n)+1;
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0]-1;
            int v = edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        depthNode.resize(n,0);
        ancestor.assign(n, vector<int>(cols, -1));
        dfs(0,-1,adj,0);
        fillTable();
       
        // init of the power 2 table -> precomputing
        vector<int>power2(n+1);
        power2[0] = 1;
        for(int i=1;i<=n;i++)
        {
            power2[i] = (2LL * power2[i-1]) % mod;
        }
        
        vector<int>ans;
        for(auto &query:queries)
        {
            int u = query[0]-1;
            int v = query[1]-1;

            int du = depthNode[u];
            int dv = depthNode[v];
            int lca = findLCA(u,v);
            int dlca = depthNode[lca];
            int d = (du+dv)-(2*dlca);

            int push = d==0?0:power2[d-1];
            ans.push_back(push);
        }

        return ans;
        
    }
};