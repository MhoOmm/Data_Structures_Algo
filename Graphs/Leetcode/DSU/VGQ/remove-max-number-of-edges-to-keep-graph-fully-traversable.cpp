class DSU{
    public:
       vector<int>parent;
       vector<int>rank;
       int components;

       DSU(int n){
        parent.resize(n+1);
        rank.resize(n+1,0);
        components = n;
        for(int i=1;i<=n;i++)
        {
            parent[i] =i;
        }
       }

       int find(int x)
       {
        if(x==parent[x])
        {
            return x;
        }
        return parent[x] = find(parent[x]);
       }

       void Union(int x,int y)
       {
        int parx = find(x);
        int pary = find(y);
        if(parx==pary)return;

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }else if(rank[pary]>rank[parx])
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
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DSU alice(n);
        DSU bob(n);

        // sorting out the type 3 edges first
        sort(begin(edges),end(edges),[](vector<int>&vec1,vector<int>&vec2){
            return vec1[0]>vec2[0];
        });
        int edgeCount = 0;
        for(auto &edge:edges)
        {
            int type = edge[0];
            int u = edge[1];
            int v = edge[2];

            if(type==3)
            {
                if(alice.find(u)!=alice.find(v) && bob.find(u)!=bob.find(v))
                {
                    alice.Union(u,v);
                    bob.Union(u,v);
                    edgeCount++;
                    alice.components--;
                    bob.components--;
                }
            }else{
                if(type==1)
                {
                    if(alice.find(u)!=alice.find(v))
                    {
                        alice.Union(u,v);
                        edgeCount++;
                        alice.components--;
                    }
                }else{
                    if(bob.find(u)!=bob.find(v))
                    {
                        bob.Union(u,v);
                        edgeCount++;
                        bob.components--;
                    }
                }
            }
        }

        int ans =  edges.size()-edgeCount;
        return (alice.components==1 && bob.components==1)?ans:-1;
    }
};