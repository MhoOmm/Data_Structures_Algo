// bfs approach
class Solution {
public:
    int n1,n2;
    // bfs(i,adj2,iter2,visited,k-1);
    void bfs(int src,vector<vector<int>>&adj,vector<int>&iter,vector<int>&visited,int k){
        queue<int>q;
        q.push(src);
        visited[src] = true;
        iter[src] = 0;
        while(!q.empty() && k >= 0)
        {
            int size = q.size();
            while(size--)
            {
                int node = q.front();
                q.pop();
                iter[src]+=1;
                for(auto &neig:adj[node])
                {
                    if(!visited[neig])
                    {
                        visited[neig] = true;
                        q.push(neig);
                    }
                }
            }
            k--;
        }
    }
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
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
        vector<int>iter1(n1,0);
        vector<int>iter2(n2,0);
        
        // bfs for each node in the first tree
        for(int i=0;i<n1;i++)
        {
            vector<int>visited(n1,false);
            bfs(i,adj1,iter1,visited,k);
        }
        // bfs for each node in the second tree
        for(int i=0;i<n2;i++)
        {
            vector<int>visited(n2,false);
            bfs(i,adj2,iter2,visited,k-1);
        }
        int maxReachableSecond = *max_element(iter2.begin(),iter2.end());
        for(int i=0;i<n1;i++)
        {
            iter1[i] += maxReachableSecond;
        }
        return iter1;
    }
};

// dfs approach
class Solution {
public:

    int dfs(int curr, unordered_map<int, vector<int>>& adj, int d, int currNodeKaParent) {
        if(d < 0)
            return 0;
        
        int count = 1; 

        for(int &ngbr : adj[curr]) {
            if(ngbr != currNodeKaParent) {
                count += dfs(ngbr, adj, d-1, curr);
            }
        }

        return count;
    }

    vector<int> findCount(vector<vector<int>>& edges, int d) {
        int N = edges.size()+1;

        //adjacency list
        unordered_map<int, vector<int>> adj;
        for(auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> result(N);
        for(int i = 0; i < N; i++) {
            result[i] = dfs(i, adj, d, -1);
        }

        return result;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        
        int N = edges1.size() + 1;

        vector<int> result1 = findCount(edges1, k); 
        vector<int> result2 = findCount(edges2, k-1); 

        int maxTargetNodesCount = *max_element(begin(result2), end(result2));
        
        for(int i = 0; i < result1.size(); i++) {
            result1[i] += maxTargetNodesCount;
        }

        return result1;
    }
};