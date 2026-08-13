// bfs approach
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


// dfs version
class Solution {
public:

    bool dfs(int node, vector<int>& mark, vector<vector<int>>& adj)
    {
        for(auto &neig : adj[node])
        {
            // Unvisited
            if(mark[neig] == -1)
            {
                mark[neig] = 1 - mark[node];

                if(!dfs(neig, mark, adj))
                    return false;
            }
            // Already visited and same color
            else if(mark[neig] == mark[node])
            {
                return false;
            }
        }

        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes)
    {
        vector<vector<int>> adj(n + 1);

        for(auto &edge : dislikes)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> mark(n + 1, -1);
        for(int i = 1; i <= n; i++)
        {
            if(mark[i] == -1)
            {
                mark[i] = 0;

                if(!dfs(i, mark, adj))
                    return false;
            }
        }

        return true;
    }
};