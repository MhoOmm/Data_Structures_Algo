class Solution {
public:
    vector<int> corpFlightBookings(vector<vector<int>>& bookings, int n) {
        vector<int>diffArr(n+1,0);
        for(auto &e:bookings)
        {
            int start = e[0];
            int end = e[1];
            int seat = e[2];

            diffArr[start-1] += seat;
            diffArr[end] -= seat;
        }

        vector<int>result;
        int cumSum  =0;
        for(int i=0;i<n;i++)
        {
            cumSum += diffArr[i];
            result.push_back(cumSum);
        }

        return result;

    }
};