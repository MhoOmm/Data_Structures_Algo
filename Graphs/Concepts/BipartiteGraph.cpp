// DFS approach
class Solution {
  public:
  
    bool BiDfs(vector<int>adj[],vector<int>&color,bool currcolor, int node)
    {
        color[node]=currcolor;
        for(int i=0;i<adj[node].size();i++)
        {
            int neig=adj[node][i];
            if(color[neig]==color[node])
            {
                return false;
            }
            if(color[neig]==-1)
            {
                int colorv=1-currcolor;
                if(!BiDfs(adj,color,colorv,neig))
                {
                    return false;   
                }
            }
        }
        return true;
    }
    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>adj[V];
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(V,-1);
        
        for(int i = 0;i<V ;i++)
        {
            if(color[i]==-1)
            {
               if(!BiDfs(adj,color,1,i)) 
               {
                   return false;
               }
            }
        }
        
        return true;
        
    }
};


// BFS solution

class Solution {
  public:
  
    bool BiBfs(vector<int>adj[],vector<int>&color,bool currcolor, int currnode){
        queue<int>q;
        color[currnode]=currcolor;
        q.push(currnode);
        
        while(!q.empty())
        {
            int u= q.front();
            q.pop();
            
            for(int i=0;i<adj[u].size();i++)
            {
                int neig = adj[u][i];
                if(color[neig]==color[u])
                {
                    return false;
                }
                if(color[neig])
                {
                    int colorv = 1 - currcolor;
                    if(!BiBfs(adj,color,colorv,neig))
                    {
                        return false;
                    }
                }
            }
            return true;
        }
    }

    bool isBipartite(int V, vector<vector<int>> &edges) {
        // Code here
        vector<int>adj[V];
        for(auto &edge : edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        
        vector<int>color(V,-1);
        
        for(int i = 0;i<V ;i++)
        {
            if(color[i]==-1)
            {
               if(!BiBfs(adj,color,1,i)) 
               {
                   return false;
               }
            }
        }
        
        return true;
        
    }
};