class Solution {
public:
    vector<int>rank;
    vector<int>parent;
    int find(int x)
    {
        if(parent[x] == x)
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
            return;
        }

        if(rank[parx]>rank[pary])
        {
            parent[pary] = parx;
        }
        else if(rank[parx]<rank[pary])
        {
            parent[parx] = pary; 
        }
        else{
            parent[parx] = pary; 
            rank[pary]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        int n = equations.size();
        parent.resize(26);
        rank.resize(26,0);
        for(int i=0;i<26;i++)
        {
            parent[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            int al1 = equations[i][0]-'a';
            int al2 = equations[i][3]-'a';
            if(equations[i][1]==equations[i][2])
            {
                Union(al1,al2);
            }
        }

        // check if != but in same group -> return false else continue
        for(auto &eq:equations)
        {
            int first = eq[0]-'a';
            int second = eq[3]-'a';
            if(eq[1]!=eq[2] && find(first)==find(second))
            {
                return false;
            }
        }

        return true;
    }
};