class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfs(vector<vector<int>> &adj) {
        // Code here
        int v = adj.size();
        vector<bool>visited(v,false);
        
        queue<int>q;
        vector<int>ans;
        visited[0]=1;
        q.push(0);
        
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            ans.push_back(node);
            
            for(int i=0;i<adj[node].size();i++)
            {
                if(!visited[adj[node][i]])
                {
                    visited[adj[node][i]]=1;
                    q.push(adj[node][i]);
                }
            }
        }
        
        return ans;
    }
};