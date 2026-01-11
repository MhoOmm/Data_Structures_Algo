// dfs approach

class Solution {
public:
    bool dfs(int curr,vector<vector<int>>& graph,vector<int>&color,int currcolor)
    {
        color[curr] = currcolor;
        for(auto &neig:graph[curr])
        {
            if(color[neig]==color[curr])
            {
                return false;
            }
            if(color[neig]==-1)
            {
                int newc = 1-currcolor;
                if(dfs(neig,graph,color,newc)==false)
                {
                    return false;
                }
            }
        }
        return true;
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>color(n,-1);
        int currcolor = 0;
        for(int i =0;i<n;i++)
        {
            if(color[i]==-1)
            {
                if(dfs(i,graph,color,currcolor)==false){
                    return false;
                }
            }
        }
        return true;
    }
};