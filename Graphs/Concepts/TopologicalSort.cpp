class Solution {
  public:
  
    void toposort(int node,vector<int>adj[],vector<bool>&visited,stack<int>&s)
    {
        visited[node]=1;
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                toposort(adj[node][i],adj,visited,s);//bacho ko bhej diya pehle stack mein 
            }
        }
        s.push(node);// ab mein chala stack mein 
        
    }
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        vector<int>adj[V];
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);//directed graph
        }
        
        stack<int>s;
        vector<bool>visited(V,false);
        
        vector<int>ans;
        
        for(int i=0;i<V;i++){
            if(!visited[i])
            {
                toposort(i,adj,visited,s);
            }
        }
        
        while(!s.empty())
        {
            ans.push_back(s.top());
            s.pop();
        }
        
        return ans;
    }
};