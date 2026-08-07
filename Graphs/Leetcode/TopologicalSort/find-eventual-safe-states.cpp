class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<vector<int>>adj(n);
        vector<int>inDeg(n,0);
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<graph[i].size();j++)
            {
                adj[graph[i][j]].push_back(i);
                inDeg[i]++;
            }
        }
        vector<bool>safe(n,false);
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            safe[node] = true;
            for(auto &neig:adj[node])
            {
                inDeg[neig]--;
                if(inDeg[neig]==0)
                {
                    q.push(neig);
                }
            }
        }

        vector<int>ans;
        for(int i=0;i<n;i++)
        {
            if(safe[i])
            {
                ans.push_back(i);
            }
        }
        return ans;
    }
};