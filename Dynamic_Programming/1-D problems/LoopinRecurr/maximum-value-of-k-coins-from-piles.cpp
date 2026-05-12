// recursion + memo
class Solution {
public:
    int t[1001][2001];
    int solve(vector<vector<int>>& piles,int i, int k)
    {
        if(i>=piles.size()){
            return 0;
        }
        if(t[i][k]!=-1)
        {
            return t[i][k];
        }
        // skip
        int skip = solve(piles,i+1,k);
        // take from the current pile
        //jitna bacha hai k ka value that many can take
        int take = INT_MIN;
        int sum = 0;
        int m = piles[i].size();
        int cap = min(m,k);
        for(int j=0;j<cap;j++) 
        {
            sum += piles[i][j];
            int money = sum + solve(piles,i+1,k-(j+1));
            take  = max(take,money);
        }

        return t[i][k]= max(skip,take);
    }
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        memset(t,-1,sizeof(t));
        return solve(piles,0,k);
    }
};
