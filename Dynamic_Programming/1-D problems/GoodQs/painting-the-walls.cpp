class Solution {
public:
    int t[501][501];
    int solve(int i,int rem,vector<int>& cost, vector<int>& time)
    {
        if(rem<=0)
        {
            return 0; // no more walls to paint
        }
        if(i>=cost.size())
        {
            return INT_MAX; // very larger value to compensate invalid branch as it is not completed
        }

        if(t[i][rem]!=-1)
        {
            return t[i][rem];
        }

        // paint
        int paintnext = solve(i+1,rem-1-time[i],cost,time);
        if(paintnext!=INT_MAX){
            paintnext+=cost[i];
        }
        // no paint
        int nopaint = solve(i+1,rem,cost,time);

        return t[i][rem] = min(paintnext,nopaint);
    }
    int paintWalls(vector<int>& cost, vector<int>& time) {
        int n = cost.size();
        memset(t,-1,sizeof(t));
        return solve(0,n,cost,time);
    }
};