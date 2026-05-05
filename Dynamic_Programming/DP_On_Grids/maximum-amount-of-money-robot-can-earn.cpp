class Solution {
public:
    int n,m;
    int t[501][501][3];
    // deflect will have three values - 0,1,2
    int solve(vector<vector<int>>& coins,int i,int j,int deflect)
    {
        if(i==m-1 && j==n-1)
        {
            if(coins[i][j]<0 && deflect>0){// neutralize the last cell
                return 0;
            }
            return coins[i][j];
        }

        if(i<0||i>=m||j<0||j>=n)
        {
            return INT_MIN;
        }
        if(t[i][j][deflect]!=INT_MIN)
        {
            return t[i][j][deflect];
        }
        int skip = INT_MIN;
        // taking the coins
        int right = solve(coins,i,j+1,deflect);
        int down = solve(coins,i+1,j,deflect);
        int take = coins[i][j] + max(right,down);
        // skipping the negative coins if deflect>0
        if(coins[i][j]<0 && deflect>0)
        {
            int rightSkip = solve(coins,i,j+1,deflect-1);
            int downSkip = solve(coins,i+1,j,deflect-1);
            skip = max(rightSkip,downSkip);
        }

        return t[i][j][deflect] = max(take,skip);
    }
    int maximumAmount(vector<vector<int>>& coins) {
        m = coins.size();
        n = coins[0].size();
        for(int i=0;i<501;i++){
            for(int j=0;j<501;j++){
                for(int k=0;k<3;k++){
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(coins,0,0,2);
    }
};