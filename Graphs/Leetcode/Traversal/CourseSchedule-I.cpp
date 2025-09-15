// Kahn's Algorithm-finding cycle in DAG
class Solution {
public:
    bool canFinish(int num, vector<vector<int>>& prerequisites) {
        vector<int>adj[num];
        vector<int>inDeg(num);
        for(auto &edge:prerequisites)
        {
            int u = edge[0];
            int v = edge[1];

            // v->u
            adj[v].push_back(u);
            inDeg[u]++;
        }
        queue<int>q;
        for(int i=0;i<num;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }
        int count=0;
        while(!q.empty())
        {
            int node=q.front();
            q.pop();
            count++;
            for(int i=0;i<adj[node].size();i++)
            {
                inDeg[adj[node][i]]--;
                if(inDeg[adj[node][i]]==0)
                {
                    q.push(adj[node][i]);
                }
            }
        }

        return count==num?true:false;
    }
};

// Finding cycle in DAG using stack

