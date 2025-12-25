class Solution {
public:
    typedef long long LL;
    void dfs(int u,vector<vector<int>>&adj,unordered_set<int>&visited)
    {
        visited.insert(u);
        for(auto &neig:adj[u]){
            if(visited.find(neig)==visited.end())
            {
                dfs(neig,adj,visited);
            }
        }
    }
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n= bombs.size();
        vector<vector<int>>adj(n);

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++)
            {
                if(i == j) //same bomb
                    continue;
                
                LL x1 = bombs[i][0];
                LL y1 = bombs[i][1];
                LL r1 = bombs[i][2];
                
                LL x2 = bombs[j][0];
                LL y2 = bombs[j][1];
                LL r2 = bombs[j][2];
                                
                LL distance = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
                
                if(LL(r1*r1) >= distance) {
                    adj[i].push_back(j);
                }
            }
        }

        // dfs for every node
        int result = 0;
        unordered_set<int>visited;
        for(int i=0;i<n;i++)
        {
            dfs(i,adj,visited);
            int count = visited.size();
            result= max(result,count);
            visited.clear();
        }

        return result;
        
    }
};