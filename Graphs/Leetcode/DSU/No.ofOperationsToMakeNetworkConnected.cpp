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
        for(int i=0;i<n;i++)
        {
            parent[i]=i;
        }
        rank.resize(n,0);
        int count=0;
        for(auto &vec:connections )
        {
            int u=vec[0];
            int v=vec[1];
            Union(u,v);
        }

        for(int i = 0;i<n;i++)
        {
            if(parent[i]==i)
            {
                count++;
            }
        }

        return count-1;
    }
};