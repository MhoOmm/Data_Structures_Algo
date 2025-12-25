class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        unordered_map<int,set<int>>adj;
        for(auto &edge:roads)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].insert(v);
            adj[v].insert(u);
        }

        int maxCount =0;
        for(int u=0;u<n;u++)
        {
            for(int v=u+1;v<n;v++)
            {
                int count = adj[u].size()+adj[v].size();
                if(adj[u].find(v)!=adj[u].end() && adj[v].find(u)!=adj[v].end())
                {
                    count--;
                }
                maxCount = max(maxCount,count);
            }
        }

        return maxCount;
    }
};