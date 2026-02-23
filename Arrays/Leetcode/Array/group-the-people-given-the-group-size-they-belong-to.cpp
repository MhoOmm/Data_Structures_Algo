class Solution {
public:
    vector<vector<int>> groupThePeople(vector<int>& group) {
        int n = group.size();
        vector<vector<int>>mp(n+1);
        vector<vector<int>>ans;

        for(int i=0;i<n;i++)
        {
            int num = group[i];
            mp[num].push_back(i);
            if(mp[num].size() == num)
            {
                ans.push_back(mp[num]);
                mp[num] = {};
            }
        }

        return ans;
    }
};