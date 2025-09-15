#include<iostream>
using namespace std;
#include<vector>
#include<queue>
class Solution {
public:
    vector<vector<int>>direct{{-1,0},{1,0},{0,-1},{0,1}};
    int numEnclaves(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>>visited(m,vector<int>(n,0));

        typedef pair<int,int>p;
        queue<p>q;

        for (int i=0;i<n;i++)
        {
           for( int j=0;j<m;j++)
           {
                if (i==0||j==0||i==n-1||j==m-1)
                {
                    if(grid[i][j] == 1)
                    {
                        q.push({i,j});
                        visited[i][j]=1;
                    }
                }
           }
          
        }

        while(!q.empty())
        {
            int N=q.size();
            while(N--)
            {
                p curr= q.front();
                q.pop();
                int i=curr.first;
                int j= curr.second;
                visited[i][j]=1;

                for (vector<int>&dir:direct){
                        int new_i=i+dir[0];
                        int new_j=j+dir[1];

                        if (new_i>=0 && new_i<m && new_j>=0 && new_j<n && !visited[new_i][new_j]==1&& grid[new_i][new_j]==1)
                        {
                            visited[new_i][new_j]=1;
                            q.push({new_i,new_j});
                        } 
                }

             }
        }
        int enclave=0;
        for (int i=0;i<n;i++)
        {
           for( int j =0;j<m;j++)
           {
                if (grid[i][j]==1 && visited[i][j]==0)
                {
                    enclave++;
                }
                
           }
          
        }

        return enclave;
        
    }
};