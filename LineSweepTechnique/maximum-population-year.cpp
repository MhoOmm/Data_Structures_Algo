class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        int n = logs.size();
        vector<pair<int,int>>events;
        for(auto &log:logs)
        {
            events.push_back({log[0],+1});
            events.push_back({log[1],-1});
        }
        sort(events.begin(),events.end());
        int currSum =0;
        int maxSum =0;
        int minYear = 2050;

        for(auto &e:events)
        {
            currSum += e.second;
            if(currSum>maxSum)
            {
                maxSum = currSum;
                minYear = e.first;
            }
        }

        return minYear;
    }
};