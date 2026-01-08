class Solution {
public:
    typedef pair<int,pair<int,int>> pp;
    vector<vector<int>>directions{{0,1},{1,0},{-1,0},{0,-1}};
    int minTimeToReach(vector<vector<int>>& moveTime) {
        int n = moveTime.size();
        int m = moveTime[0].size();
        vector<vector<int>>result(n,vector<int>(m,INT_MAX));
        priority_queue<pp,vector<pp>,greater<pp>> pq;
        result[0][0] =  0;
        pq.push({0,{0,0}});
        while(!pq.empty()){
            int currTime = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;

            pq.pop();
            if(i==n-1 && j==m-1)
            {
                return currTime;
            }
            for(auto &dir:directions){
                int ni = i + dir[0];
                int nj = j + dir[1];
                if(ni>=0 && nj>=0 && ni<n && nj<m)
                {
                    int wait = max(moveTime[ni][nj]-currTime , 0);
                    int nt = wait + currTime + 1;
                    if (result[ni][nj]> nt)
                    {
                        result[ni][nj] = nt;
                        pq.push({nt,{ni,nj}});
                    }
                }
            }
        }
        return -1;
    }
};