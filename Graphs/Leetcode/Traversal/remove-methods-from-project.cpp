class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>>adj(n);
        for(auto &edge:invocations)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v); // directed edge
        }

        // bfs to mark all infected nodes
        vector<int>sus(n,false);
        vector<int>visited(n,false);
        queue<int>q;
        q.push(k);
        sus[k] = true;
        visited[k] = true;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &neig:adj[node])
            {
                if(!visited[neig])
                {
                    sus[neig] = true;
                    visited[neig] =true;
                    q.push(neig);
                }
            }
        }

        // now checking if the edge to be included doesnt have a direct edge to a infected node -> check if all have indegree zero
        for(auto &edge:invocations)
        {
            int u = edge[0];
            int v = edge[1];
            if(!sus[u] && sus[v])
            {
                // we cannot remove anything and hence have to remove every node
                vector<int>ans;
                for(int i=0;i<n;i++)
                {
                    ans.push_back(i);
                }
                return ans;
            }
        }
        // else keep only those who are not sus
        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(!sus[i])
            {
                ans.push_back(i);
            }
        }
        return ans;

    }
};