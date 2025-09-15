//recur+memo
class Solution {
public:
    int n;
    int t[301][5001];
    int solve(int i,int amount,vector<int>&coins)
    {
        if(i>=n || amount<0)
        {
            return 0;
        }
        if(amount==0)
        {
            return 1;
        }
        if(t[i][amount]!=-1)
        {
            return t[i][amount];
        }
        int include = solve(i, amount - coins[i], coins);
        int exclude = solve(i + 1, amount, coins);

        return t[i][amount]= include + exclude;

    }
    int change(int amount, vector<int>& coins) {
        n=coins.size();
        memset(t,-1,sizeof(t));
        return solve(0,amount,coins);
    }
};

// bottom up approach 
class Solution {
public:
    int combi(vector<int>& coins, int amount, int n) {
        vector<vector<int>> t(n+1, vector<int>(amount+1));
        
        for(int i = 0; i<n+1; i++) {
            for(int j = 0; j<amount+1; j++) {
                if(j == 0) {
                    t[i][j] = 1;
                } else if(i == 0) {
                    t[i][j] = 0;
                } else if(coins[i-1] <= j) {
                    t[i][j] = t[i][j-coins[i-1]] + t[i-1][j];
                } else {
                    t[i][j] = t[i-1][j];
                }
            }
        }
        
        return t[n][amount];
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        
        return combi(coins, amount, n);
    }
};