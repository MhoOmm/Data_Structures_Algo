class Solution {
public:
    int minCost(string colors, vector<int>& nt) {
        int n = colors.size();
        
        int sum = 0;
        int currSum = nt[0];
        int currMax = nt[0];
        for(int i=0;i<n-1;i++)
        {
            if(colors[i]==colors[i+1])
            {
                currSum += nt[i+1];
                currMax = max(currMax,nt[i+1]);
            }else{
                sum += currSum - currMax;
                currSum = nt[i+1];
                currMax  = nt[i+1];
            }
        }
        sum += currSum - currMax;

        return sum;
    }
};