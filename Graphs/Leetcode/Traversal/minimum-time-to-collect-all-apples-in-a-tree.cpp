class Solution {
public:
    int Dfs(vector<vector<int>>&adj,int curr,int parent,vector<bool>& hasApple)
    {
        int time = 0;
        for(int child:adj[curr])
        {
            if(child==parent)
            {
                continue;
            }

            int childtime = Dfs(adj,child,curr,hasApple);

            if(childtime || hasApple[child])
            {
                time+=2+childtime;
            }
        }

        return time;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        
        vector<vector<int>>adj(n);

        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return Dfs(adj,0,-1,hasApple);
    }
};