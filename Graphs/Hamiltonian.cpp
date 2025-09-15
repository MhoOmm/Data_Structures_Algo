#include<iostream>
using namespace std;

#include<vector>

//to find hamiltonian path- visit every node exaclty one time. edges cannot be traversed 
// more than one time 

// agar koi edge na visit kar pao tab bhi chalega but nodes saare bas ekbaar travel hone chahiye 

class Solution
{
    public:
    
    bool DFS(int node,vector<vector<int>>&adj,vector<bool>&visited,int &count,int n)
    {
        visited[node]=1;
        count++;
        
        if (count==n)
        {
            return 1;
        }
        
        for (int j=0;j<adj[node].size();j++)
        {
            if (!visited[adj[node][j]])
            {
               if(DFS(adj[node][j],adj,visited,count,n))
               {
                   return 1;
               }
            }
        }
        
        visited[node]=0;
        count--;
        return 0;
    }
    bool check(int N,int M,vector<vector<int>> Edges)
    {
        
        // code here
        
        vector<vector<int>>adj(N);
        
        //making the adjacency matrix
        for (int i=0;i<M;i++)
        {
            adj[Edges[i][0]-1].push_back(Edges[i][1]-1);
            adj[Edges[i][1]-1].push_back(Edges[i][0]-1); // link created both sides 
        }
        
        vector<bool>visited(N,0);
        int count=0;
        
        for (int i=0;i<N;i++)
        {
            if(DFS(i,adj,visited,count,N))
            {
                return 1;
            }
        }
        return 0;
    }
};
 

//{ Driver Code Starts.
int main()
{
	int t;
	cin>>t;
	while(t--){
    	int N,M,X,Y;
    	cin>>N>>M;
    	vector<vector<int>> Edges;
    	for(int i=0;i<M;i++)
    	{
    		cin>>X>>Y;
    		Edges.push_back({X,Y});
    	}
    	Solution obj;
    	if(obj.check(N,M,Edges)){
    		cout<<"1"<<endl;
    	}
    	else
    	cout<<"0"<<endl;
	
cout << "~" << "\n";
}
}
// } Driver Code Ends