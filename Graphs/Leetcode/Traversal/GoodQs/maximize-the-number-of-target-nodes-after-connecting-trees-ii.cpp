// Brute-force - TLE (n^2 approach)
class Solution {
public:
    int n1,n2;
    void bfs(int src,vector<vector<int>>&adj,vector<int>&iter,vector<int>&visited,bool even){
        queue<int>q;
        q.push(src);
        visited[src] = true;
        iter[src] = 0;
        int div = 0;
        if(!even)
        {
            div = 1;
        }
        int dist = 0;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                if(dist%2==div){
                    iter[src]+=1;
                }
                for(auto &neig:adj[node])
                {
                    if(!visited[neig])
                    {
                        visited[neig] = true;
                        q.push(neig);
                    }
                }
            }
            dist++;
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n1 = edges1.size() + 1;
        n2 = edges2.size() + 1;

        // making of the two graphs
        vector<vector<int>>adj1(n1);
        vector<vector<int>>adj2(n2);

        for(auto &edge:edges1)
        {
            int u = edge[0];
            int v = edge[1];
            adj1[u].push_back(v);
            adj1[v].push_back(u);
        }
        for(auto &edge:edges2)
        {
            int u = edge[0];
            int v = edge[1];
            adj2[u].push_back(v);
            adj2[v].push_back(u);
        }
        // two vectors for storing the maximum amount of reachable nodes
        vector<int>even(n1,0);
        vector<int>odd(n2,0);
        
        // bfs for each node in the first tree
        for(int i=0;i<n1;i++)
        {
            vector<int>visited(n1,false);
            bfs(i,adj1,even,visited,true);
        }
        // bfs for each node in the second tree
        for(int i=0;i<n2;i++)
        {
            vector<int>visited(n2,false);
            bfs(i,adj2,odd,visited,false);
        }
        int maxReachOddDist = *max_element(odd.begin(),odd.end());
        for(int i=0;i<n1;i++)
        {
            even[i] += maxReachOddDist;
        }
        return even;
    }
};

// optimised approach
