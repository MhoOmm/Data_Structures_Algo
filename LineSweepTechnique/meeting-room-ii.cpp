class Solution {
  public:
    int minMeetingRooms(vector<int> &start, vector<int> &end) {
        // code here
        vector<pair<int,int>>events;
        for(int i =0;i<start.size();i++)
        {
            events.push_back({start[i],+1});
            events.push_back({end[i],-1});
        }
        sort(events.begin(),events.end());
        
        int maxRoom = 1;
        int currRoom = 1;
        for(auto &e:events)
        {
            currRoom += e.second;
            maxRoom = max(maxRoom,currRoom);
        }
        
        return maxRoom-1;
    }
};
