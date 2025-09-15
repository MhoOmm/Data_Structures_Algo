class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        vector<int>inDeg(V);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);//directed graph
            inDeg[v]++;
        }
        
        vector<int>ans;
        
        queue<int>q;
        for(int i = 0;i<V;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            for(int i=0;i<adj[node].size();i++)
            {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                }
            }
            
        }
        
        return ans;
    }
};