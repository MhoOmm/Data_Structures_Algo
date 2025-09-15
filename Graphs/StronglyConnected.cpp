#include<iostream>
using namespace std;
#include <vector>
#include <stack>


void topo(int node ,vector<vector<int>>&adj,vector<bool>&visited,stack<int>&s)
{
    visited[node]=1;
    //look at its all neighbour
    for (int j=0;j<adj[node].size();j++)
    {
        if(!visited[adj[node][j]])
        {
            topo(adj[node][j],adj,visited,s);
        }

    }
    s.push(node);

}

void dfs(int node,vector<vector<int>>&adj2,vector<bool>&visited)
{
    visited[node]=1;

    for (int j=0;j<adj2[node].size();j++)
    {
        if (!visited[adj2[node][j]])
        {
            dfs(adj2[node][j],adj2,visited);
        }

    }
}
int kosaraju(int v , vector<vector<int>>&adj)
{
    //topological sort 

    stack<int>s;
    vector<bool>visited(v,0);

    for( int i=0;i<v;i++)
    {
        if(!visited[i])
        {
            topo(i,adj,visited,s);
        }
    }

    //reverse the edges/transpose the graph 

    vector<vector<int>>adj2;

    for(int i=0;i<v;i++)
    {
        for (int j=0;j<adj[i].size();j++)
        {
            int u=i;
            int v= adj[i][j];
            adj2[v].push_back(u);
        }
    }

    //pop the elements form stack 

    for ( int i=0;i<v;i++)
    {
        visited[i]=0;
    }
    int scc=0;
    while(s.empty())
    {
        int node=s.top();
        s.pop();
        if(!visited[node])
        {
            scc++;
            dfs(node,adj2,visited);
        }
    }

    return scc;
}