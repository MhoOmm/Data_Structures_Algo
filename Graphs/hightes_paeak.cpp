#include<iostream>
using namespace std;
#include<vector>
#include<queue>

class Solution {
public:
    vector<vector<int>> direct={{-1,0},{1,0},{0,-1},{0,1}};
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        
        int m = isWater.size();
        int n = isWater[0].size();
        vector<vector<bool>>visited(m,vector<bool>(n,0));

        typedef pair<int,int> p;
        int co=0;
        queue<p>q;


        for (int i=0;i<m;i++)
        {
            for (int j=0;j<n;j++)
            {
                if(isWater[i][j]==1)
                {
                    q.push({i,j});
                    isWater[i][j]=0;
                    visited[i][j]=1;
                    
                }
            }
        }

        while(!q.empty())
        {
            int N= q.size();
            while(N--)
            {
                p curr= q.front();
                q.pop();
                int i=curr.first;
                int j= curr.second;
                isWater[i][j]=co;

                for (vector<int>&dir:direct){
                        int new_i=i+dir[0];
                        int new_j=j+dir[1];

                        if (new_i>=0 && new_i<m && new_j>=0 && new_j<n && !visited[new_i][new_j]==1)
                        {
                            visited[new_i][new_j]=1;
                            isWater[new_i][new_j]=co+1;
                            q.push({new_i,new_j});
                        }
            }
            co++;
        }
    }
    }
};


//highly optimised
//study later the solution 

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        const int n = isWater.size(), m = isWater[0].size(), inf = n + m;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) isWater[i][j] ^= 1;

        // Take min dist up/left
        for (int i=0; i<n; ++i)
            for (int j=0; j<m; ++j) {
                if (!isWater[i][j]) continue;
                const int left = (j > 0) ? isWater[i][j-1] : inf;
                const int top = (i > 0) ? isWater[i-1][j] : inf;
                isWater[i][j] = min(left, top) + 1;
            }
        
        // Take min dist right/down
        for (int i=n-1; i>=0; --i)
            for (int j=m-1; j>=0; --j) {
                if (!isWater[i][j]) continue;
                int right = (j < m-1) ? isWater[i][j+1] : inf;
                int bottom = (i < n-1) ? isWater[i+1][j] : inf;
                isWater[i][j] = min(isWater[i][j], min(right, bottom) + 1);
            }
        
        return isWater;
    }
};

