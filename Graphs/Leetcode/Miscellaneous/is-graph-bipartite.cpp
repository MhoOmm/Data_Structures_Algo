// dfs approach

class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& graph,vector<int>&color,int currcolor)
    {
        color[curr] = currcolor;
        for(auto &neig:graph[curr])
        {
            if(color[neig]==color[curr])
            {
                return false;
            }
            if(color[neig]==-1)
            {
                int newc = 1-currcolor;
                if(dfs(neig,graph,color,newc)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int currcolor = 0;
        for(int i =0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,graph,color,currcolor)==false){
                    return false;
                }
            }
        }
        return true;
    }
};


// bfs approach

class Solution {
public:
    bool bfs(int i,vector<vector<int>>& adj,vector<int>&color,int currcolor)
    {
        queue<int>q;
        q.push(i);
        color[i] = currcolor;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &neig:adj[node]){
                if(color[neig]==color[node])
                {
                    return false;
                }
                if(color[neig] == -1)
                {
                    color[neig] = 1-color[node];
                    q.push(neig);
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int currcolor = 0;
        for(int i =0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(bfs(i,graph,color,currcolor)==false){
                    return false;
                }
            }
        }
        return true;
    }
};