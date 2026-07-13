class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>>directions{{0,1},{1,0},{0,-1},{-1,0}};
    int minTimeToReach(vector<vector<int>>& mt) {
        int m = mt.size();
        int n = mt[0].size();

        priority_queue<pp,vector<pp>,greater<pp>>pq;
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        pq.push({0,{0,0}});
        result[0][0] = 0;
        int cross = 1;

        while(!pq.empty()){
            int currTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i==m-1 && j==n-1)
            {
                return currTime;
            }

            for(auto &dir:directions)
            {
                int ni = i+dir[0];
                int nj = j+dir[1];
                if(ni>=0 && nj>=0 && ni<m && nj<n)
                {
                    int wait = max(mt[ni][nj] - currTime , 0 );
                    int time = wait + currTime + cross;
                    if(result[ni][nj]>time)
                    {
                        result[ni][nj]=time;
                        pq.push({time,{ni,nj}}); 
                    }
                }
            }
        }
        return -1;
    }
};