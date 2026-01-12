class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(i==parent[i])
        {
            return i;
        }

        return parent[i] = find(parent[i]);
    }

    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);
        if(parx==pary)
        {
            return;
        }

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }
        else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }
        else {
            parent[parx] = pary;
            rank[pary]++; 
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        parent.resize(n);
        rank.resize(n);
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
            rank[i] =0;
        }
        for(auto &edge:edges)
        {
            int u = edge[0];
            int v = edge[1];
            Union(u,v);
        } 

        unordered_map<int,int>mp;
        for(int i =0;i<n;i++)
        {
            mp[find(i)]++;
        }

        long long count = 0;
        for(int i=0;i<n;i++)
        {
            count+= n-mp[parent[i]];
        }
        return count/2;
    }
};