//recursion + memoization 
//O(n*365)
class Solution {
public:
    int t[366][400];
    int solve(vector<int>& days, vector<int>& costs,int i,int endD){
        if(i>= days.size())
        {
            return 0;
        }

        if(t[i][endD]!=-1)
        {
            return t[i][endD];
        }

        if(endD>=days[i])
        {
            return t[i][endD] = solve(days,costs,i+1,endD);
        }

        int take1 = costs[0] + solve(days,costs,i+1,days[i]);
        int take7 = costs[1] + solve(days,costs,i+1,days[i]+6);
        int take30 = costs[2] + solve(days,costs,i+1,days[i]+29);

        return t[i][endD]= min({take1,take7,take30});
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        memset(t,-1,sizeof(t));
        return solve(days,costs,0,0);
    }
};

// bottom up 

//O(n)
class Solution {
    public:
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            int n=days.size();
            int last_day=days[n-1];
            unordered_set<int>st(begin(days),end(days));
            vector<int>t(last_day+1,0);
            t[0]=0;
            for(int i=1;i<=last_day;i++){
    
                if(st.find(i)==st.end())
                {
                    t[i]=t[i-1];//skip
                    continue;
                }
    
                t[i]=INT_MAX;
                int day1=costs[0]+t[max(i-1,0)];
                int day7=costs[1]+t[max(i-7,0)];
                int day30=costs[2]+t[max(i-30,0)];
    
                t[i]=min({t[i],day1,day7,day30});
    
            }
    
            return t[last_day];
        }
    };