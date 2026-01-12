class Solution {
public:
    void dfs(string &src, string &dest,
             unordered_map<string, vector<pair<string,double>>>& adj,
             double prod, double &ans,
             unordered_set<string>& visited) {

        if (visited.count(src)) return;

        visited.insert(src);

        if (src == dest) {
            ans = prod;
            return;
        }

        for (auto &neigh : adj[src]) {
            if (ans != -1.0) return; 

            string neig = neigh.first;
            double val = neigh.second;

            dfs(neig, dest, adj, prod * val, ans, visited);
        }
    }

    vector<double> calcEquation(vector<vector<string>>& equations,vector<double>& values,vector<vector<string>>& queries) {

        unordered_map<string, vector<pair<string,double>>> mp;

        for (int i = 0; i < equations.size(); i++) {
            string u = equations[i][0];
            string v = equations[i][1];
            double val = values[i];

            mp[u].push_back({v, val});
            mp[v].push_back({u, 1.0 / val});
        }

        vector<double> result;

        for (auto &query : queries) {
            string s1 = query[0];
            string s2 = query[1];

            double ans = -1.0;

            if (mp.count(s1) && mp.count(s2)) {
                unordered_set<string> visited;
                dfs(s1, s2, mp, 1.0, ans, visited);
            }

            result.push_back(ans);
        }

        return result;
    }
};
