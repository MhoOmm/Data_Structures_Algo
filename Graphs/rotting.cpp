#include<iostream>
using namespace std;
#include<vector>
#include <queue>

class Solution {
public:
    vector<vector<int>> direct={{-1,0},{1,0},{0,-1},{0,1}};
    int orangesRotting(vector<vector<int>>& grid) {
        
            typedef pair<int,int> p;
            int m=grid.size();
            int n= grid[0].size();
            int fresh=0; 

            queue<p>q;

            // to intiliase the total no of fresh oranges and 
            // get the 2 oranges in the queue

            for(int i =0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    if(grid[i][j]==1)
                    {
                        fresh++;
                    }
                    if(grid[i][j]==2)
                    {
                        q.push({i,j});
                    }
                }
            }

            if (fresh==0)
            {
                return 0;
            }

            int minutes=0;

            while (!q.empty())
            {
                int N= q.size();
                while(N--)
                {
                    p curr=q.front();
                    q.pop();

                    int i=curr.first;
                    int j=curr.second;

                    for (vector<int>&dir:direct)
                    {
                        int new_i=i+dir[0];
                        int new_j=j+dir[1];

                        if (new_i>=0 && new_i<m && new_j>=0 && new_j<n && grid[new_i][new_j]==1)
                        {
                            grid[new_i][new_j]=2;
                            q.push({new_i,new_j});
                            fresh--;
                        }
                    }
                }
                minutes++;
                
            }


            if (fresh)
            {
                return -1;
            }
            else {
                return minutes-1;
            }
        }
            
};