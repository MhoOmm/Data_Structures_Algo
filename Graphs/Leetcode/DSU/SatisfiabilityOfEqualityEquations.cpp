class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int i,vector<int>&parent)
    {
        if(i==parent[i])
        {
            return i;
        }

        return parent[i]=find(parent[i],parent);
    }

    void Union(int x,int y,vector<int>&parent,vector<int>&rank)
    {
        int par_x=find(x,parent);
        int par_y=find(y,parent);

        if(par_x>par_y)
        {
            parent[par_y]=par_x;
        }
        else if(par_x<par_y)
        {
            parent[par_x]=par_y; 
        }
        else{
            parent[par_x]=par_y;
            rank[par_x]++;
        }
    }
    bool equationsPossible(vector<string>& equations) {
        parent.resize(26);
        rank.resize(26);
        for(int i=0;i<26;i++)
        {
            parent[i]=i;
            rank[i]=1;
        }
        for(string &s:equations)
        {
            if(s[1]=='=')
            {
                Union(s[0]-'a',s[3]-'a',parent,rank);
            }
        }
        for(string &s:equations)
        {
            if(s[1]=='!')
            {
               if(find(s[0]-'a',parent) == find(s[3]-'a',parent)){
                    return false;
               }
            }
        }

        return true;
    }
};