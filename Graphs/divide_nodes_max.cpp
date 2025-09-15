#include<iostream>
using namespace std;
#include<vector>
#include<queue>
//my solution 
class Solution {
public:
    bool bipartite(unordered_map<int,vector<int>>&adj,vector<int>&colour,int curr,int currcol)
    {
        colour[curr]=currcol;

        for(int j=0;j<adj[curr].size();j++)
        {
            int ngbr=adj[curr][j];

            if(colour[curr]==colour[ngbr])
            {
                return 0;
            }
            if(colour[ngbr]==-1)
            {
                if(!bipartite(adj,colour,ngbr,1-currcol))
                {
                    return 0;
                }
            }
        }
        return 1;
    }

    int bfs(unordered_map<int,vector<int>>&adj,int currnode,int n)
    {
        vector<bool>visited(n,0);
        queue<int>q;
        q.push(currnode);
        visited[currnode]=1;

        int level=1;
        while(!q.empty())
        {
            int size=q.size();
            while(size--)
            {
                int curr=q.front();
                q.pop();
            
                for(int j=0;j<adj[curr].size();j++)
                {
                    int ngbr=adj[curr][j];
                    if(visited[ngbr]==1)
                    {
                        continue;
                    }
                    q.push(ngbr);
                    visited[ngbr]=1;

                }
            }
            level++;
        }


        return level-1;//as one extra is added when the que gets empty

    }
    int maxgrp(unordered_map<int,vector<int>>&adj,vector<bool>&visited,int curr,vector<int>&levels)
    {
        int max_grp=levels[curr];
        visited[curr]=1;
        for(int j=0;j<adj[curr].size();j++)
        {
            int ngbr=adj[curr][j];
            if (!visited[ngbr])
            {
                max_grp=max(max_grp,maxgrp(adj,visited,ngbr,levels));


            }
        }
        return max_grp;
    }
    int magnificentSets(int n, vector<vector<int>>& edges) {

        unordered_map<int,vector<int>>adj;

        //making the adjacency matrix 
        for(int i=0;i<edges.size();i++)
        {
            int u=edges[i][0]-1;
            int v=edges[i][1]-1;//converting to 0 based index

            if (u != v) { // Ignore self-loops
                adj[u].push_back(v);
                adj[v].push_back(u);
            }

        }

        //bipartite check for the graph 
        vector<int>colour(n,-1);
        for( int node=0;node<n;node++)
        {
            if(colour[node]==-1)
            {
                if(!bipartite(adj,colour,node,1))
                {
                    return -1;

                }

            }
        }
        //bfs to get the maximum amount of groups possible

        vector<int>levels(n,0);
        for(int node=0;node<n;node++)
        {
            levels[node]=bfs(adj,node,n);
        }

        int maxgrp_each_cmp=0;
        vector<bool>visited(n,0);

        for(int node=0;node<n;node++)
        {
            if(!visited[node])
            {
                maxgrp_each_cmp+=maxgrp(adj,visited,node,levels);

            }
        }

        return maxgrp_each_cmp;

        
    }
};



//optimised code to infinity 
class Solution {
public:
    int magnificentSets(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n + 1);
        vector<int> visited(n + 1, -1);
        
        for (const auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int maxGroups = 0;
        unordered_set<int> componentNodes;
        
        for (int i = 1; i <= n; i++) {
            if (visited[i] != -1) continue;
            
            componentNodes.clear();
            findConnectedComponent(i, graph, componentNodes);
            
            int maxDepth = -1;
            for (int node : componentNodes) {
                maxDepth = max(maxDepth, getMaxDepth(node, componentNodes, graph, visited));
            }
            
            if (maxDepth == -1) return -1;
            maxGroups += maxDepth;
        }
        
        return maxGroups;
    }

private:
    void findConnectedComponent(int node, vector<vector<int>>& graph, unordered_set<int>& componentNodes) {
        componentNodes.insert(node);
        for (int neighbor : graph[node]) {
            if (componentNodes.count(neighbor) == 0) {
                findConnectedComponent(neighbor, graph, componentNodes);
            }
        }
    }

    int getMaxDepth(int start, unordered_set<int>& componentNodes, vector<vector<int>>& graph, vector<int>& visited) {
        for (int node : componentNodes) visited[node] = -1;
        
        queue<int> q;
        int depth = 1;
        
        q.push(start);
        visited[start] = 1;
        
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            
            for (int neighbor : graph[cur]) {
                if (visited[neighbor] == -1) {
                    visited[neighbor] = visited[cur] + 1;
                    depth = max(depth, visited[neighbor]);
                    q.push(neighbor);
                } else if (abs(visited[cur] - visited[neighbor]) != 1) {
                    return -1;
                }
            }
        }
        
        return depth;
    }
};