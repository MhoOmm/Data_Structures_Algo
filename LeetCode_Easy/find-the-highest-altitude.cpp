class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        int cumSum = 0;
        int maxSum = 0;
        for(int i=0;i<n;i++)
        {
            cumSum += gain[i];
            maxSum = max(cumSum,maxSum);
        }
        return maxSum;
    }
};