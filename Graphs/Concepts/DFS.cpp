class Solution {
  public:
  
    void DFS (vector<vector<int>>& adj,vector<bool>&visited,int u,vector<int>&ans)
    {
        visited[u]=1;
        ans.push_back(u);
        for(int i=0;i<adj[u].size();i++)
        {
            if(!visited[adj[u][i]])
            {
                DFS(adj,visited,adj[u][i],ans);
            }
        }
    }
    vector<int> dfs(vector<vector<int>>& adj) {
        // Code here
        int n = adj.size();// no of vertices
        vector<bool>visited(n,false);
        
        vector<int>ans;// dfs array
        
        DFS(adj,visited,0,ans);
        
        return ans;
    }
};