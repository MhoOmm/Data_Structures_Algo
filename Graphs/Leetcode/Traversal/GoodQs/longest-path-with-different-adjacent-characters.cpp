class Solution {
public:
    int result;
    int solve(int node,int parent,string &s,vector<vector<int>>&adj)
    {
        int longChild = 0;
        int secLongChild = 0;
        // getting the length of both the children
        for(auto &neig:adj[node])
        {
            if(neig==parent)
            {
                continue;
            }
            int childPath = solve(neig, node, s, adj);
            if(s[neig]==s[node])
            {
                continue;
            }
            if (childPath > longChild)
            {
                secLongChild = longChild;
                longChild = childPath;
            }
            else if (childPath > secLongChild)
            {
                secLongChild = childPath;
            }
        }
        // only root
        int root_good = 1;
        // only one child included
        int one_child_good = max(longChild,secLongChild) + root_good;
        // sum of all three
        int sum = longChild + secLongChild + root_good;

        result = max({result,sum,root_good,one_child_good});
        return one_child_good;
    }
    int longestPath(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>>adj(n);
        for(int i=1;i<n;i++)
        {
            int u = i;
            int v = parent[i];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        result = 0;
        solve(0,-1,s,adj);
        return result;
    }
};