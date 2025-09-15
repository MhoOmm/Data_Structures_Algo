#include<iostream>
using namespace std;
#include <vector>
#include<stack>
// m colouring problem 

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
class Solution {
  public:

    bool dfs(int node,int v, int edges[101][101],vector<int>&color,int m)
    {
        //checking for every colour::

        for (int i=0;i<m;i++)
        {
            //checking for each node
            int ispossible=1;
            for(int j=0;j<v;j++)
            {

                if(edges[node][j]&&color[j]==i)
                {
                    ispossible=0;
                    break;
                }

            }
            if (ispossible==0)
            {
                continue;//check next colour
            }
            color[node]=i;

            bool isp=1;

            for(int j=0;j<v;j++)
            {
                if(edges[node][j]&&color[j]==-1)
                {
                    if (!dfs(j,v,edges,color,m))
                    {
                        isp=0;
                        break;
                    }
                }
            }


            if(isp)
            {
                return 1;
            }
            color[node]=-1;
        }
        return 0;

    }
    bool graphColoring(int v, int edges[101][101], int m) {
        // code here

        vector<int>color(v,-1);
        for (int i=0;i<v;i++)
        {
            if (color[i]==-1&&!dfs(i,v,edges,color,m))
            {
                return 0;
            }
        }
        return 1;
        
    }
};



// more optimised approach
