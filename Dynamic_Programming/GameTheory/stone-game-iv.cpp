class Solution {
public:
    // alice -> 1,true
    // bob -> 0,false
    int t[100001][2];
    bool solve(int n,bool turn)
    {
        if(n==0)
        {
            if(turn==true)
            {
                return false;
            }
            else{
                return true;
            }
        }
        if(t[n][turn]!=-1)
        {
            return t[n][turn];
        }
        bool ans = turn ? false : true;
        for (int i = 1; i * i <= n; i++)
        {
            if (turn)
            {
                ans = ans || solve(n - i * i, !turn);
            }
            else
            {
                ans = ans && solve(n - i * i, !turn);
            }
        }
        return t[n][turn]=ans;
    }
    bool winnerSquareGame(int n) {
        memset(t,-1,sizeof(t));
        return solve(n,true);
    }
};