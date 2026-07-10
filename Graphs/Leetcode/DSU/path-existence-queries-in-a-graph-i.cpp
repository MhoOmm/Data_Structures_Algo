//  brute force approach - build the whole graph and then check bfs for every query
// TLE :)
class Solution {
public:
    bool bfs(int src,int dest,vector<vector<int>>&adj,int n)
    {
        queue<int>q;
        vector<bool>visited(n,false);
        visited[src] = true;
        q.push(src);

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            if(node==dest)
            {
                return true;
            }
            for(auto & neig:adj[node])
            {
                if(!visited[neig])
                {
                    visited[neig] = true;
                    q.push(neig);
                }
            }
        }

        return false;
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        vector<vector<int>>adj(n);
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(nums[j]-nums[i])>maxDiff)
                {
                    continue;
                }else{
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }  
        }
        vector<bool>ans;
        for(auto &edge:queries)
        {
            int u = edge[0];
            int v = edge[1];
            if(bfs(u,v,adj,n))
            {
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

// DSU approach - minus the bfs solution
// tle - still the problem is the making of the graph
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int u)
    {
        if(parent[u] == u)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void Union(int u,int v){
        int parx = find(u);
        int pary = find(v);

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
        }else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        rank.resize(n,0);
        parent.resize(n);
        vector<bool>ans;
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(abs(nums[j]-nums[i])>maxDiff)
                {
                    continue;
                }else{
                    Union(i,j);
                }
            }  
        }

        // now finding if they are in the same component
        for(auto &edge:queries)
        {
            int u  = edge[0];
            int v  = edge[1];
            if(find(u)==find(v))
            {
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};
// optimised solution - if the array is already sorted then we 
// can check adjacent elements and make the graph
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int u)
    {
        if(parent[u] == u)
        {
            return u;
        }
        return parent[u] = find(parent[u]);
    }

    void Union(int u,int v){
        int parx = find(u);
        int pary = find(v);

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
        }else{
            parent[parx] = pary;
            rank[pary]++;
        }
    }
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        
        rank.resize(n,0);
        parent.resize(n);
        vector<bool>ans;
        for(int i=0;i<n;i++)
        {
            parent[i] = i;
        }

        for(int i=0;i<n-1;i++)
        {
            if(abs(nums[i]-nums[i+1])<=maxDiff)
            {
                Union(i,i+1);
            }
        }

        // now finding if they are in the same component
        for(auto &edge:queries)
        {
            int u  = edge[0];
            int v  = edge[1];
            if(find(u)==find(v))
            {
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};

// best solution - component based approach
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        vector<int>component(n,-1);
        vector<bool>ans;
        int comp = 0;
        component[0] = comp;
        for(int i=1;i<n;i++)
        {
            if(abs(nums[i]-nums[i-1])>maxDiff)
            {
                comp++;
            }
            component[i] = comp;
        }

        // now finding if they are in the same component
        for(auto &edge:queries)
        {
            int u  = edge[0];
            int v  = edge[1];
            if(component[u]==component[v])
            {
                ans.push_back(true);
            }else{
                ans.push_back(false);
            }
        }
        return ans;
    }
};