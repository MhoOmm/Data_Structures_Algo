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


class Solution {
public:
    int n1,n2;
    unordered_map<int, vector<int>> getAdj(vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for(auto &edge : edges) {
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return adj;
    }
    // dfs(0,parent,markT1,zeroMark1,oneMark1,adj1);
    void dfs(int node,int parent,vector<int>&mark,int &zeroMark,int &oneMark,unordered_map<int,vector<int>>&adj)
    {
        if(mark[node]==0)
        {
            zeroMark++;
        }else{
            oneMark++;
        }

        for(auto &neig:adj[node])
        {
            if(neig==parent)
            {
                continue;
            }
            mark[neig] = (mark[node]==1)?0:1;
            dfs(neig,node,mark,zeroMark,oneMark,adj);
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        n1  = edges1.size() + 1;
        n2  = edges2.size() + 1;
        // making the adj
        unordered_map<int, vector<int>> adj1 = getAdj(edges1);
        unordered_map<int, vector<int>> adj2 = getAdj(edges2);

        // counting marked for first tree
        vector<int>markT1(n1,-1);
        int zeroMark1 = 0;
        int oneMark1 = 0;
        markT1[0] = 0; // marking the first node as zero
        dfs(0,-1,markT1,zeroMark1,oneMark1,adj1);
        
        // counting marked for first tree
        vector<int>markT2(n2,-1);
        int zeroMark2 = 0;
        int oneMark2 = 0;
        markT2[0] = 0; // marking the first node as zero
        dfs(0,-1,markT2,zeroMark2,oneMark2,adj2);

        int maxMarkedT2 = max(zeroMark2,oneMark2);
        vector<int>result(n1,0);
        for(int i=0;i<n1;i++)
        {
            result[i] = (markT1[i]==0 ? zeroMark1 : oneMark1) + maxMarkedT2;
        }
        return result;
    }
};