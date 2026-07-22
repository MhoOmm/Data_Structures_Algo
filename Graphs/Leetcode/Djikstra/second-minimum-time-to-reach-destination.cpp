class Solution {
public:
    typedef pair<int,int> pp;
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>>adj(n+1);
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,1}); // {currTime,src}
        vector<int>d1(n+1,INT_MAX);
        vector<int>d2(n+1,INT_MAX);
        d1[1] = 0;
        while(!pq.empty())
        {
            auto [currTime,node] = pq.top();
            pq.pop();
            if(node==n && d2[n]!=INT_MAX)
            {
                break;
            }
            int div = currTime/change;
            if(div%2==0){
                // even time -> we can pass freely
                for(auto &neig:adj[node])
                {
                    int nt = currTime + time;
                    if(nt<d1[neig])
                    {
                        //first visit
                        d1[neig] = nt;
                        pq.push({nt,neig});
                    }else if(nt < d2[neig] && nt > d1[neig])
                    {
                        // second visit
                        d2[neig] = nt;
                        pq.push({nt,neig});
                    }
                }
            }else{
                 // odd time -> we have to wait
                for(auto &neig:adj[node])
                {
                    int nt = (div+1)*change + time;
                    if(nt<d1[neig]){
                        //first visit
                        d1[neig] = nt;
                        pq.push({nt,neig});
                    }else if(nt < d2[neig] && nt > d1[neig])
                    {
                        // second visit
                        d2[neig] = nt;
                        pq.push({nt,neig});
                    }
                }               
            }
        }
        return d2[n];
    }
};