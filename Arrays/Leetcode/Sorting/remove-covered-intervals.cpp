class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),[](auto &a,auto &b){
            if(a[0]==b[0]){
                return a[1]>b[1];
            }
            else{
                return a[0]<b[0];
            }
        });
        int maxend = intervals[0][1];
        int count = 1;
        for(int i=1;i<n;i++)
        {
            // if the current range is within the maximum interval then no need to add count
            if(intervals[i][1]<=maxend)
            {
                continue;
            }
            else{
                count++;
                maxend = intervals[i][1];
            }
        }
        return count;
    }
};