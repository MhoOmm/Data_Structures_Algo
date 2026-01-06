class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);
        vector<int>inDeg(n);
        for(auto &edge:relations){
            int u = edge[0];
            int v = edge[1];
            adj[u-1].push_back(v-1);
            inDeg[v-1]++;
        }
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(inDeg[i]==0)
            {
                q.push(i);
            }
        }
        vector<int>maxi = time;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                int top = q.front();
                q.pop();
                for(int neig:adj[top])
                {
                    inDeg[neig]--;
                    maxi[neig] = max(maxi[neig],time[neig] + maxi[top]);
                    if(inDeg[neig]==0)
                    {
                        q.push(neig);
                    }
                }
            }
        }
        return *max_element(begin(maxi),end(maxi));
    }
};