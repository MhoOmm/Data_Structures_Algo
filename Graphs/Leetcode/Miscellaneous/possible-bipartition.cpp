class Solution {
public:
    bool bfs(int i,vector<vector<int>>&adj,vector<int>&color,int currC)
    {
        color[i] = currC;
        queue<int>q;
        q.push(i);
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &neig:adj[node])
            {
                if(color[neig]==color[node])
                {
                    return false;
                }
                if(color[neig]==-1)
                {
                    color[neig] = 1-color[node];
                    q.push(neig);
                }
            }
        }

        return true;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<vector<int>>adj(n);
        for(auto &edge:dislikes)
        {
            int u = edge[0]-1;
            int v = edge[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int>color(n,-1);
        int currC = 0;
        for(int i=0;i<n;i++)
        {
            if(color[i] ==-1)
            {
                if(bfs(i,adj,color,currC)==false)
                {
                    return false;
                }
            }
        }

        return true;

    }
};