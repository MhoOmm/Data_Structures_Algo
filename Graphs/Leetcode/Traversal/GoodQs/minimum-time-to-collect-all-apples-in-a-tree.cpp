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

// another approach  -> if my child subtree has an apple i will add 2
class Solution {
public:
    int time;
    bool dfs(int node,int parent,vector<vector<int>>&adj,vector<bool>&hasApple){
        bool thisApple = hasApple[node]; // whether this node has an apple
        for(auto &child:adj[node])
        {
            if(parent==child)continue; // leaf node skip if dont have apple

            if(dfs(child,node,adj,hasApple))
            {
                time+=2;
                thisApple = true; // whether any of my child has apple
            }
        }
        return thisApple;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>>adj(n);
        for(int i=0;i<edges.size();i++)
        {
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        time = 0;
        dfs(0,-1,adj,hasApple);
        return time;
    }
};