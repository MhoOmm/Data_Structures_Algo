class Solution {
  public:
    vector<int>parent;
    vector<int>rank;
    int find(int i,vector<int>&parent){
        if(parent[i]==i)
        {
            return i;
        }
        return parent[i]=find(parent[i],parent);
    }
    
    void Union(int x,int y,vector<int>&parent,vector<int>&rank)
    {
        int par_x = find(x,parent);
        int par_y = find(y,parent);
        
        if(rank[par_x]>rank[par_y])
        {
            parent[par_y]=par_x;
        }else if(rank[par_x]<rank[par_y]){
            parent[par_x]=par_y;
        }
        else{
            parent[par_x]=par_y;
            rank[par_y]++;
        }
    }
    // Function to detect cycle using DSU in an undirected graph.
    int detectCycle(int V, vector<int> adj[]) {
        // Code here
        parent.resize(V);
	    rank.resize(V, 0);
	    
	    for(int i = 0; i<V; i++)
	        parent[i] = i;
        for(int u = 0;u<V;u++)
        {
            for(int v=0;v<adj[u].size();v++)
            {
                int neig = adj[u][v];
                if(u<neig)
                {
                    int par_u = find(u,parent);
                    int par_v = find(neig,parent);
                    if(par_u==par_v)
                    {
                        return true;
                    }else{
                        Union(par_u,par_v,parent,rank);
                    }
                }
            }
        }
        
        return false;
    }
};