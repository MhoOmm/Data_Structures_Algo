class Solution {
  public:
    int overlapInt(vector<vector<int>> &arr) {
        // code here
        vector<pair<int,int>>events;
        for(auto &inter:arr)
        {
            int st = inter[0];
            int en = inter[1];
            events.push_back({st,+1});
            events.push_back({en,-1});
        }
        sort(events.begin(), events.end(), [](pair<int,int> &a, pair<int,int> &b){
            if (a.first == b.first)
                return a.second > b.second;
            return a.first < b.first;
        });
        int currinter = 1;
        int maxinter = 1;
        for(auto &e:events)
        {
            currinter += e.second;
            maxinter = max(maxinter,currinter);
        }
        return  maxinter-1;
    }
};
