class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        vector<pair<int,int>>events;
        for(auto &trip:trips)
        {
            int pas = trip[0];
            int start = trip[1];
            int end = trip[2];
            events.push_back({start,pas});
            events.push_back({end,-1*pas});
        }
        sort(begin(events),end(events));
        int passengers =0;
        for(auto &tr:events)
        {
            passengers += tr.second;
            if(passengers>capacity)
            {
                return false;
            }
        }
        return true;
    }
};