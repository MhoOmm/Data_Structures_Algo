// Best Time to Buy and Sell Stock -ii

// Recursion + Memoization
class Solution {
public:
    int n;
    int t[300001][2];
    long solve(int i, bool buy,vector<int>&prices){
        if(i==n)return 0;

        int profit = 0;

        if(t[i][buy]!=-1)return t[i][buy];

        if(buy){

            profit = max(-prices[i]+solve(i+1,0,prices), 0+solve(i+1,1,prices));

        }else{
            profit = max(prices[i]+solve(i+1,1,prices), 0+solve(i+1,0,prices));
        }
        return t[i][buy] = profit;
    }
    int maxProfit(vector<int>& prices) {
        n = prices.size();
        memset(t,-1,sizeof(t));
        return solve(0,1,prices);
    }
};

// bottom up
