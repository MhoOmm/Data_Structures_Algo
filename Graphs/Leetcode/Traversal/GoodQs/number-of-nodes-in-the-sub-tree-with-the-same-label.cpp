class Solution {
public:
    vector<int> dfs(vector<vector<int>>&adj,string &labels,int node,int par,vector<int> &result)
    {
        vector<int>mycount(26,0);
        char label = labels[node];
        mycount[label-'a'] = 1;

        // give me my child vector count
        for(auto &neig:adj[node])
        {
            if(neig==par)
            {
                continue;
            }
            vector<int>childCount(26,0);
            childCount = dfs(adj,labels,neig,node,result);
            for(int i=0;i<26;i++)
            {
                mycount[i] += childCount[i];
            }
        }
        // result of the subtree of this node is the mycount value of the label
        result[node] = mycount[label-'a'];
        return mycount;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        vector<int>result(n,0);
        dfs(adj,labels,0,-1,result);
        return result;
    }
};