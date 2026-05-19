class Solution {
public:
    int t[50005][2];
    // 1 = can buy or skip
    // 0 = sell or no_sell
    int solve(int i,int buy,vector<int>&prices,int fee)
    {
        if(i>=prices.size())
        {
            return 0;
        }
        if(t[i][buy]!=-1)
        {
            return t[i][buy];
        }

        // if !buy then compulsory buy
        if(buy)
        {
            // buy or skip
            int take = solve(i+1,0,prices,fee) - prices[i];
            int nt = solve(i+1,1,prices,fee);

            return t[i][buy] = max(take,nt);
        }

        // sell
        int sell = prices[i] + solve(i+1,1,prices,fee) - fee;
        // no_sell
        int no_sell =  solve(i+1,0,prices,fee);

        return t[i][buy] = max(sell,no_sell);
    }
    int maxProfit(vector<int>& prices, int fee) {
        memset(t,-1,sizeof(t));
        return solve(0,1,prices,fee);
    }
};