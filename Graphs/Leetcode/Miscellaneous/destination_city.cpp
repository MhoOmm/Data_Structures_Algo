class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        int n = paths.size();
        unordered_map<string,vector<string>>mp;
        for(auto &edge:paths)
        {
            string u = edge[0];
            string v = edge[1];
            mp[u].push_back(v);
        }
        for(auto &edge:paths)
        {
            string u = edge[0];
            string v = edge[1];
            if(mp.find(v)==mp.end())
            {
                return v;
            }
        }

        return "";
    }
};