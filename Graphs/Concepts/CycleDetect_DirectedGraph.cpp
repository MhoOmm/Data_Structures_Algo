//  dfs code : using the in current recursion array
class Solution {
  public:
  
    bool isDfs( vector<int>adj[],vector<bool>&visited,vector<bool>&inRecur,int node)
    {
        visited[node]=true;
        inRecur[node]=true;
        
        for(int i=0;i<adj[node].size();i++)
        {
            if(!visited[adj[node][i]])
            {
                if(isDfs(adj,visited,inRecur,adj[node][i]))
                {
                    return true;//baad mein kahin se true return hua
                }
            }
            else if(inRecur[adj[node][i]])
            {
                return true;
            }
        }
        
        inRecur[node]=false;
        return false;
    }
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<int>adj[V];
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);//directed graph
        }
        
        vector<bool>visited(V,false);
        vector<bool>inRecur(V,false);
        
        for(int i =0;i<V;i++)
        {
            if(!visited[i])
            {
                if(isDfs(adj,inRecur,visited,i))
                {
                    return true;
                }
            }
        }
        
        return false;
        
    }
};


// bfs code :Toplogical sort using bfs

class Solution {
  public:
 
    bool isCyclic(int V, vector<vector<int>> &edges) {
        // code here
        
        vector<int>InDeg(V);
        vector<int>adj[V];
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            
            adj[u].push_back(v);//directed graph
            InDeg[v]++;
        }
        
        queue<int>q;
        for(int i=0;i<V;i++)
        {
            if(InDeg[i]==0)
            {
                q.push(i);
            }
        }
        
        int count =0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            
            for(int i=0;i<adj[node].size();i++)
            {
                InDeg[adj[node][i]]--;
                if(InDeg[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                }
                
            }
        }
        
        if(count==V)
        {
            return false;
        }else{
            return true;
        }
        
    }
};

