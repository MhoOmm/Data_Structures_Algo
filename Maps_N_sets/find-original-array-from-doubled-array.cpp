class Solution {
public:
    vector<int> findOriginalArray(vector<int>& change) {

        int n = change.size();
        if(n%2!=0)
        {
            return {};
        }
        unordered_map<int,int>mp;
        for(auto &num:change)
        {
            mp[num]++;
        }
        sort(begin(change),end(change));
        vector<int>og;

        for(auto &num:change)
        {
            if (mp[num] == 0) continue;
            if (mp[2 * num] == 0) return {}; 

            og.push_back(num);
            mp[num]--;
            mp[2 * num]--;
        }

        return og;
        
    }
};