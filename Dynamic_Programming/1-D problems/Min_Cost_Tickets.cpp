//recursion + memoization 
//O(n)
class Solution {
    public:
        int t[366];
        int memoized(vector<int>& days, vector<int>& costs, int& n, int idx) {
            if(idx >= n)return 0;
                    
            if(t[idx] != -1)return t[idx];
            
            int cost_1 = costs[0] + memoized(days, costs, n, idx+1);
            
            int i= idx;
            while(i < n && days[i] < days[idx]+7) {
                i++;
            }
            int cost_7 = costs[1] + memoized(days, costs, n, i);
    
            int j = idx;
            while(j < n && days[j] < days[idx]+30) {
                j++;
            }
            int cost_30 = costs[2] + memoized(days, costs, n, j);
            
            
            return t[idx] = min({cost_1, cost_7, cost_30});
        }
        
        int mincostTickets(vector<int>& days, vector<int>& costs) {
            memset(t, -1, sizeof(t));
            int n = days.size();
            return memoized(days, costs, n, 0);
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