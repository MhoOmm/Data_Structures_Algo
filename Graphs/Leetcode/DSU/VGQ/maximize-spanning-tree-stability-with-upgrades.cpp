class DSU{
    public:
       vector<int>parent,rank;
       DSU(int n)
       {
          parent.resize(n);
          rank.resize(n,0);
          for(int i=0;i<n;i++)
          {
            parent[i] = i;
          }
       }

       int find(int x)
       {
        if(parent[x]==x)
        {
            return x;
        }
        return parent[x] = find(parent[x]);
       }

       void Union(int x,int y)
       {
        int parx = find(x);
        int pary = find(y);
        if(parx==pary)
        {
            return ;
        }
        if(rank[parx]>rank[pary]){
            parent[pary] = parx;
        }
        else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }
        else{
            parent[parx] = pary;
            rank[pary]++;
        }
       }
};
class Solution {
public:
    bool check(int mid,vector<vector<int>>& edges, int k,int n)
    {
        // checking for ability to merge
        DSU dsu(n);
        vector<pair<int,int>>potential;
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int st = edge[2];
            int must = edge[3];

            if(must==1)
            {
                if(st < mid)
                {
                    // cannot spanning tree with this mid. this mid should be smallest
                    return false;
                }
                dsu.Union(u,v);
            }else{ // must==1
                if(st>=mid){// this poses no harm can be included
                   dsu.Union(u,v);
                }
                else if (st*2 >= mid){
                    //potential upgrade candidate
                    potential.push_back({u,v});
                }
            }
        }
        // checking for potential upgrade candidates
        for(auto &edge:potential)
        {
            int u = edge.first;
            int v = edge.second;
            if(dsu.find(u)!=dsu.find(v))
            {
                if(k<=0)
                {
                    return false;
                }
                dsu.Union(u,v);
                k--;
            }
        }
        // checking for spanning tree
        int par = dsu.find(0);
        // all should have the same parent
        for(int node=1;node<n;node++)
        {
            if(dsu.find(node)!=par)
            {
                return false;
            }
        }
        return true;
    }
    int maxStability(int n, vector<vector<int>>& edges, int k) {
        // checking if any cycle exists in the input using dsu
        DSU dsu(n); // init a dsu rank and parent vector
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            int st = edge[2];
            int must = edge[3];

            if(must==1)
            {
                if(dsu.find(u)==dsu.find(v))
                {
                    return -1;
                }
                dsu.Union(u,v);
            }
        }
        // binary search on answer
        int l = 1;
        int r = 2*1e5; // upgraded strength max val

        int result = -1;
        while(l<=r)
        {
            int mid = l+(r-l)/2;
            if(check(mid,edges,k,n))
            {
                result = mid;
                l = mid+1; //maximise the minimum stability
            }else{
                r = mid-1;
            }
        }
        return result;
    }
};