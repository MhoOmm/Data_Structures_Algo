// recursion + memo
class Solution {
public:
    int mod = 1e9+7;
    int t[101][201];
    int solve(vector<int>& loc,int i, int finish, int fuel)
    {
        if(fuel<0)
        {
            return 0;
        }
        if(t[i][fuel]!=-1)
        {
            return t[i][fuel];
        }

        int ways = 0;
        if(i==finish)
        {
            ways++;
        }
        // but if finish still count for other possibilities 
        // and for normal cases explore all j
        for(int j=0;j<loc.size();j++)
        {
            if(i!=j)
            {
                int newFuel = fuel - abs(loc[i]-loc[j]);
                ways = (ways+solve(loc,j,finish,newFuel))%mod;
            }
        }

        return t[i][fuel] = ways;

    }
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        memset(t,-1,sizeof(t));
        return solve(locations,start,finish,fuel);
    }
};