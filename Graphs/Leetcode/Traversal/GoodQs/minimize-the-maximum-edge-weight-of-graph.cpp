// applying binary search on answer -> inverting the edges and checking for zero to reach all nodes
class Solution {
public:
    bool canReachZero(int mid,int n,vector<vector<pair<int,int>>>&invadj)
    {
        vector<bool>visited(n,false);
        queue<int>q;
        q.push(0);
        visited[0] = true;

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            for(auto &neigN:invadj[node]){
                int neig = neigN.first;
                int neigwt = neigN.second;

                if(neigwt<=mid && !visited[neig])
                {
                    q.push(neig);
                    visited[neig] = true;
                }
            }
        }
        // now we check if all are visited
        for(int i=0;i<n;i++)
        {
            if(!visited[i])
            {
                return false;
            }
        }
        return true;
    }
    int minMaxWeight(int n, vector<vector<int>>& edges, int threshold) {
        vector<int>outDeg(n);
        vector<vector<pair<int,int>>>invadj(n);
        int r = INT_MIN;  // maxWeight

        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];
            outDeg[u]++;

            r = max(r,wt);
            // inverting the edge
            // invadj[v] = {u,wt}; u->v but we need to invert 
            invadj[v].push_back({u,wt});
        }

        // binary search on answer
        int l = 0;
        int result = INT_MAX;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(canReachZero(mid,n,invadj))
            {
                result = mid;
                r = mid-1;
            }else{
                l = mid+1;
            }
        }

        return result==INT_MAX?-1:result;
    }
};