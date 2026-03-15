class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        // unordered_map<string,string>mp;
        // for(auto &path:paths)
        // {
        //     string u = path[0];
        //     string v = path[1];
        //     mp[u] = v;
        // }

        // for(auto &path:paths)
        // {
        //     if(mp.find(path[1])==mp.end())
        //     {
        //         return path[1];
        //     }
        // }

        unordered_set<string>st;
        for(auto &path:paths)
        {
            st.insert(path[0]);
        }

        for(auto &path:paths)
        {
            if(st.find(path[1])==st.end())
            {
                return path[1];
            }
        }

        return "";
    }
};