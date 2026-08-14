class Solution {
public:
    int n,m;
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>>directions{{0,1},{0,-1},{-1,0},{1,0}};
    bool isSafe(int i,int j){
        return (i<n && i>=0 && j>=0 && j<m);
    }
    int minimumEffortPath(vector<vector<int>>& heights) {
        n = heights.size();
        m = heights[0].size();
        vector<vector<int>>dist(n,vector<int>(m,INT_MAX));
        dist[0][0] = 0;
        priority_queue<pp,vector<pp>,greater<pp>>pq;
        pq.push({0,{0,0}});

        while(!pq.empty())
        {
            int effortTillNow = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();
            if(i==n-1 && j==m-1)
            {
                return effortTillNow;
            }

            for(auto &dir:directions)
            {
                int ni = i+dir[0];
                int nj = j+dir[1];

                if(isSafe(ni,nj))
                {
                    int diff = abs(heights[i][j]-heights[ni][nj]);
                    int maxEffortTillNow = max(effortTillNow,diff);
                    if(maxEffortTillNow < dist[ni][nj])
                    {
                        dist[ni][nj] = maxEffortTillNow;
                        pq.push({maxEffortTillNow,{ni,nj}});
                    }
                }
            }
        }

        return dist[n-1][m-1];
    }
};