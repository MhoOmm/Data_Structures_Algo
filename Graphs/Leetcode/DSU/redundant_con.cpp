#include<iostream>
using namespace std;
#include<vector>
#include<queue>

// bfs approach
class Solution {
public:

    bool bfs(vector<vector<int>>&adj,vector<bool>&visited,int u ,int v)
    {
        queue<int>q;
        //start from u and go to v 
        q.push(u);

        while(!q.empty())
        {
            int node=q.front();
            q.pop();

            if(node==v)
            {
                return 1;//path already exists between them 
                //adding extra will create a redundant edge
            }

            for(int j=0;j<adj[node].size();j++)
            {
                int ngbr=adj[node][j];
                if(!visited[ngbr])
                {
                    visited[ngbr]=1;
                    q.push(ngbr);
                }
            }

        }

        return 0;//no path exists between the nodes
      

    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n=edges.size();
        vector<vector<int>>adj(n+1);
        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            vector<bool>visited(n,0);

            if(!adj[u].empty() && !adj[v].empty() && bfs(adj,visited,u,v))
            {
                return edges[i];
            }
            ans[u].push_back(v);
            ans[v].push_back(u);

        }
        return {}
    }
};

//dfs approach
class Solution {
public:
    bool dfs(unordered_map<int,vector<int>>&adj,int u,int v, vector<bool>&visited)
    {
        visited[u]=1;
        if(u==v)
        {
            return 1;
        }
        //check for neighbours
        for(int &ngbr:adj[u])
        {
            if(visited[ngbr])
            {
                continue;
            }
            if(dfs(adj,ngbr,v,visited))
            {
                return 1;
            }
        }
        return 0;
    }
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {

        int n= edges.size();

        unordered_map<int,vector<int>>adj;

        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            vector<bool>visited(n,0);

            if(adj.find(u)!=adj.end() && adj.find(v)!=adj.end() && dfs(adj,u,v,visited))
            {
                return edges[i];
            }
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};

// dsu approach

class dsu{
    public:
    vector<int>rank;
    vector<int>parent;
    dsu(int n) {
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i = 1; i <= n; i++) {
            parent[i] = i;
            rank[i] = 0;
        }
    }
    int find(int x)
    {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x]=find(parent[x]);
    }
    void Union(int u, int v)
    {

        int par_x=find(u);
        int par_y=find(v);

        if( par_x == par_y)
        {
            return;
        }
        if( rank[par_x]>rank[par_y])
        {
            parent[par_y]=par_x;
        }
        else if( rank[par_x]<rank[par_y])
        {
            parent[par_x]=par_y;
        }
        else{
            parent[par_y]=par_x;
            rank[par_x]++;

        }

    }

};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n=edges.size();

        dsu du(n);

        for(int i=0;i<n;i++)
        {
            int u=edges[i][0];
            int v=edges[i][1];

            if(du.find(u)==du.find(v))
            {
                return edges[i];
            }
            du.Union(u,v);

        }

        return {};//if no edge is found to be redundant
        
    }
};