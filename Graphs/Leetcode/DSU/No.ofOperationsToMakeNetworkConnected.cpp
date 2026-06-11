class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i )
    {
        if(i==parent[i])
        {
            return i;
        }
        return parent[i]=find(parent[i]);
    }

    void Union(int x,int y)
    {
        int par_x = find(x);
        int par_y = find(y);
        if(rank[par_x]>rank[par_y])
        {
            parent[par_y]=par_x;
        }else if(rank[par_y]>rank[par_x])
        {
            parent[par_x]=par_y;
        }else{
            parent[par_x]=par_y;
            rank[par_y]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size()<n-1)
        {
            return -1;
        }
        parent.resize(n);
        for(int i = 0; i<n; i++)
            parent[i] = i;
        rank.resize(n,0);
        int count=n;
        for(auto &vec:connections )
        {
            if(find(vec[0])!=find(vec[1]))
            {
                count--;
                Union(vec[0],vec[1]);
            }
        }

        return count-1;
    }
};



// alternate

class Solution {
public:
    vector<int>parent;
    vector<int>rank;
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

        if(parx==pary)return;

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }else if(rank[pary]>rank[parx])
        {
            parent[parx] = pary;
        }else{
           parent[parx] = pary; 
           rank[pary]++;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n,0);
        int edges = connections.size();
        if(edges<n-1)
        {
            return -1;
        }
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        // for making connections
        int grp = 0;
        for(int i=0;i<edges;i++)
        {
            int x = connections[i][0];
            int y = connections[i][1];

            if(find(x)!=find(y))
            {
                Union(x,y);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(find(i)==i) // in the same group
            {
                grp++;
            }

        }

        return grp-1;
    }
};