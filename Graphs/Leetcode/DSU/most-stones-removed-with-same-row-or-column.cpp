class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i)
    {
        if(parent[i]==i)
        {
            return i;
        }
        return parent[i] = find(parent[i]);
    }
    void Union(int x,int y)
    {
        int parx = find(x);
        int pary = find(y);

        if(parx == pary)
        {
            return ;
        }

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }else if(rank[pary] > rank[parx])
        {
            parent[parx] = pary;
        }
        else {
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        parent.resize(n);
        rank.resize(n);
        for(int i =0;i<n;i++)
        {
            parent[i] = i;
            rank[i] = 1;
        }

        for(int i=0;i<n;i++)
        {
            for(int j = i+1;j<n;j++)
            {
                if(stones[i][0]==stones[j][0] || stones[i][1]==stones[j][1])
                {
                    Union(i,j);
                }
            }
        }

        int grp = 0 ;

        for(int i=0;i<n;i++)
        {
            if(parent[i] == i)
            {
                grp++;
            }
        }

        return n-grp;  
    }
};