//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution
{
	public:
    //Function to return a list of lists of integers denoting the members 
    //of strongly connected components in the given graph.
    
    void dfs(int node,vector<int>adj[],vector<bool>&visited,vector<int>&disc,vector<int>&low,stack<int>&s,vector<bool>&instack,vector<vector<int>> &ans,int &timer)
    {
        visited[node]=1;
        disc[node]=low[node]=timer;
        s.push(node);
        instack[node]=1;
        
        for(int j=0;j<adj[node].size();j++)
        {
            int neib=adj[node][j];
            if(!visited[neib])
            {
                timer++;
                dfs(neib,adj,visited,disc,low,s,instack,ans,timer);
                low[node]=min(low[node],low[neib]);
            }
            else{
                if (instack[neib])
                {
                    low[node]=min(low[node],disc[neib]);
                }
            }
        }
        
        if (disc[node]==low[node])
        {
            vector<int>temp;
            while(!s.empty()&&s.top()!=node)
            {
                temp.push_back(s.top());
                instack[s.top()]=0;
                s.pop();
            }
            temp.push_back(node);
            instack[node]=0;
            s.pop();
            sort(temp.begin(),temp.end());
            
            ans.push_back(temp);
            
        }
    }
    
    vector<vector<int>> tarjans(int V, vector<int> adj[])
    {
        //code here
        
        
        vector<vector<int>>ans;
        
        vector<int>disc(V);
        vector<int>low(V);
        
        vector<bool>visited(V,0);
        stack<int>s;
        vector<bool>instack(V,0);
        int timer=0;
        
        for(int i=0;i<V;i++)
        {
            if(!visited[i])
            {
                dfs(i,adj,visited,disc,low,s,instack,ans,timer);
                
            }
        }
        
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};

//{ Driver Code Starts.


int main()
{
    
    int t;
    cin >> t;
    while(t--)
    {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for(int i = 0; i < E; i++)
        {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        vector<vector<int>> ptr = obj.tarjans(V, adj);

        for(int i=0; i<ptr.size(); i++)
        {
            for(int j=0; j<ptr[i].size(); j++)
            {
                if(j==ptr[i].size()-1)
                    cout<<ptr[i][j];
                else
                    cout<<ptr[i][j]<<" ";
            }
            cout<<',';
        }
        cout<<endl;
    
cout << "~" << "\n";
}

    return 0;
}


// } Driver Code Ends