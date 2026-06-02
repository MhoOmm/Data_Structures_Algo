class Solution {
public:
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // L = 0 , W = 1
        int n = landStartTime.size();
        int m = waterStartTime.size();
        int minTime = INT_MAX;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                // land -> water 
                int landFin = landStartTime[i]+landDuration[i];
                int finishOption1 = max(landFin,waterStartTime[j]) + waterDuration[j];

                // water ->land
                int waterFin = waterStartTime[j] + waterDuration[j];
                int finishOption2 = max(waterFin,landStartTime[i])+landDuration[i];

                minTime = min(minTime,min(finishOption1,finishOption2));
            }
        }
        return minTime;
    }
};