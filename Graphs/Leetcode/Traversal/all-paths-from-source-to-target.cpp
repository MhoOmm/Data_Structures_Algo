class Solution {
public:
    int n;
    vector<vector<int>>ans;
    void dfs(int node,vector<vector<int>>& graph,vector<int>&result){
        if(node==n-1)
        {
            ans.push_back(result);
            return;
        }

        for(auto &neig:graph[node])
        {
            // backtracking
            result.push_back(neig);
            dfs(neig,graph,result);
            result.pop_back();
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        n = graph.size();
        vector<int>result;
        result.push_back(0);
        dfs(0,graph,result);
        return ans;
    }
};