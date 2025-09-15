class Solution {
public:

    void dfs(int node,stack<int>&s , vector<int>adj[],vector<bool>&visited)
    {}
    vector<int> findOrder(int num, vector<vector<int>>& prerequisites) {
        
        vector<int>inDeg(num);
        vector<int>adj[num];
        vector<int>result;
        for(auto &edge:prerequisites)
        {
            int u = edge[0];
            int v = edge[1];

            adj[v].push_back(u);
            inDeg[u]++;
        }

        queue<int>q;
        int count=0;
        for(int i=0;i<num;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
                result.push_back(i);
                count++;
            }
        }

        vector<int>ans;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            
            for(int i =0;i<adj[node].size();i++)
            {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]]==0)
                {
                    result.push_back(adj[node][i]);
                    q.push(adj[node][i]);
                    count++;
                }
            }
        }

        if(count!=num)
        {
            return {};
        }
        else {
            return result;
        }
    }
};