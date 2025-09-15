#include<iostream>
using namespace std;

#include<vector>
#include<queue>

class Solution {
public:

    int m,n;

    vector<vector<int>> direct={{-1,0},{1,0},{0,-1},{0,1}};

    int dfs(int i,int j ,vector<vector<int>>&grid)
    {

        if(i<0||i>=m||j<0||j>=n||grid[i][j]==0)
        {
            return 0;
        }
        int fish_count=grid[i][j];
        grid[i][j]=0;

        for (vector<int>&dir:direct){
            int new_i=i+dir[0];
            int new_j=j+dir[1];
            fish_count+=dfs(new_i,new_j,grid);
        }

        return fish_count;


    }
    int findMaxFish(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int maxfish=0;

        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (grid[i][j]>0)
                {
                    maxfish=max(maxfish,dfs(i,j,grid));//saare dfs 
                    //mein se jo max value hai wo return hojayega
                }
            }
        }

        return maxfish;
   
        
    }
};


//using bfs

class Solution {
public:

    int m,n;

    vector<vector<int>> direct={{-1,0},{1,0},{0,-1},{0,1}};

    int bfs(int i,int j ,vector<vector<int>>&grid)
    {
        queue<pair<int,int>>q;
        q.push({i,j});
        int fish_count=grid[i][j];
        grid[i][j]=0;

        while(!q.empty())
        {
            i=q.front().first;
            j=q.front().second;
            for(auto&dir:direct)
            {
                int new_i=dir[0]+i;
                int new_j=dir[1]+j;

                if(new_i>0||new_j>0||new_i<=m||new_j<=n){
                    q.push({new_i,new_j});
                    fish_count+=grid[new_i][new_j];
                    grid[new_i][new_j]=0;
                }

            }
        }

        return fish_count;
    


    }
    int findMaxFish(vector<vector<int>>& grid) {

        m = grid.size();
        n = grid[0].size();
        int maxfish=0;

        for(int i =0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (grid[i][j]>0)
                {
                    maxfish=max(maxfish,bfs(i,j,grid));//saare dfs 
                    //mein se jo max value hai wo return hojayega
                }
            }
        }

        return maxfish;
   
        
    }
};