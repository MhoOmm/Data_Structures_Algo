class Solution {
public:
    void dfs(string curr,unordered_map<string,priority_queue<string,vector<string>,greater<string>>>&adj,vector<string>&result)
    {
        while(!adj[curr].empty())
        {
            string next = adj[curr].top();
            adj[curr].pop();
            dfs(next,adj,result);
        }
        result.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        unordered_map<string,priority_queue<string,vector<string>,greater<string>>>adj;
        for(auto &edge:tickets)
        {
            string u = edge[0];
            string v = edge[1];
            adj[u].push(v);
        }

        vector<string>result;
        dfs("JFK",adj,result);
        reverse(begin(result),end(result));
        return result;
    }
};