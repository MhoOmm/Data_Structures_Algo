class Solution {
public:
    int count ;
    int dfs(int node,int par,vector<vector<int>>&adj,vector<int>& values,int k){
        int sum = values[node];
        for(auto &neig:adj[node])
        {
            if(neig!=par){
                sum += dfs(neig,node,adj,values,k);
                sum = sum%k;
            }
        }
        // if the upper loop doesnt go for leaf
        sum = sum%k;
        if(sum==0)
        {
            count++;
        }
        return sum;
    }
    int maxKDivisibleComponents(int n,vector<vector<int>>& edges,vector<int>& values,int k) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        count = 0;
        int sum = dfs(0,-1,adj,values,k);
        return count;
    } 
};