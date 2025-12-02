class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& cust) {

        int n = cust.size();
        int curr = cust[0][0];
        double wt = 0;
        for(int  i=0;i<n;i++)
        {
            if(curr<cust[i][0])
            {
                curr=cust[i][0];
            }
            curr+=cust[i][1];
            wt += (curr-cust[i][0]);
        }

        return wt/n;
    }
};