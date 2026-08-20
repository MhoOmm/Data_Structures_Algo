class Solution {
public:
    unordered_map<int,int>travB;
    bool dfsb(int node,int time,vector<vector<int>>&adj,vector<bool>&visited)
    {
        visited[node] = true;
        travB[node] = time;
        if(node == 0){
            // reached destination
            return true;
        }

        for(auto &neig:adj[node])
        {
            if(!visited[neig])
            {
                if(dfsb(neig,time+1,adj,visited)){
                    return true;
                }
            }
        }
        // we have to not include this node as bob didnt travlled it
        travB.erase(node);
        return false;
    }

    void dfsa(int node,int time,vector<vector<int>>&adj,vector<bool>&visited,vector<int>&amount,int income,int &maxI)
    {
        visited[node] = true;
        // if bob has not travelled it or alice arrived early here
        if(travB.find(node)==travB.end() || time<travB[node])
        {
            income += amount[node];
        }
        else if(time == travB[node]){
            income += amount[node]/2;
        }

        
        if(adj[node].size() == 1 && node != 0) { //leaf node
            maxI = max(income,maxI );
        }
        for(int &neig : adj[node]) {
            if(!visited[neig]) {
                dfsa(neig, time+1,adj, visited,amount, income,maxI);
            }
        }
    }
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int n = amount.size();
        vector<vector<int>>adj(n);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        // dfs for bob
        vector<bool>visited(n,false);
        int time = 0;
        dfsb(bob,time,adj,visited);

        // dfs for alice
        int maxI = INT_MIN;
        visited.assign(n,false);
        time = 0;
        dfsa(0,time,adj,visited,amount,0,maxI);

        return maxI;
    }
};