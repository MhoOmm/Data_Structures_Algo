//  tc - O(n)
class Solution {
public:
    int totalTime(vector<int>actS1,vector<int>&actD1,vector<int>&actS2,vector<int>&actD2)
    {
        // activity 1 -> activity 2 => we will first choose the shortest duration time from the first activity
        int fin1 = INT_MAX;
        for(int i=0;i<actS1.size();i++)
        {
            fin1 = min(fin1,actS1[i] + actD1[i]);
        }
        // now we can explore the possibilities with fin 1 which gives the shortest time
        int fin2 = INT_MAX;
        for(int i=0;i<actS2.size();i++)
        {
            fin2 = min(fin2,max(fin1,actS2[i])+actD2[i]);
        }

        return fin2;
    }
    int earliestFinishTime(vector<int>& landStartTime, vector<int>& landDuration, vector<int>& waterStartTime, vector<int>& waterDuration) {
        // land->water
        int ltw_time = totalTime(landStartTime,landDuration,waterStartTime,waterDuration);
        // water->land
        int wtl_time = totalTime(waterStartTime,waterDuration,landStartTime,landDuration);

        return min(ltw_time,wtl_time);
    }
};