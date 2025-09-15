#include<iostream>
using namespace std;
#include <vector>
#include <queue>



// brute force method tc:-(O(n^4)) sc:-O(n^2)
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1], visited);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) { 
                    grid[i][j] = 1;
                    
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int largest = 0;
                    
                    for(int x = 0; x < m; x++) {
                        for(int y = 0; y < n; y++) {
                            if(grid[x][y] == 1 && !visited[x][y]) {
                                largest = max(largest, DFS(grid, x, y, visited));
                            }
                        }
                    }
                    
                    maxArea = max(maxArea, largest);
                    grid[i][j] = 0; 
                }
            }
        }
        
        return (maxArea == 0) ? m * n : maxArea; 
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};

// little better approach
class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited) {
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] == 0 || visited[i][j])
            return 0;

        visited[i][j] = true;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1], visited);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]==1 && !visited[i][j])
                {
                    int size=DFS(grid,i,j,visited);
                    maxarea=max(maxarea,size);
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) { 
                    grid[i][j] = 1;
                    
                    visited=vector<vector<bool>> visited(m, vector<bool>(n, false));
                    int largest = 0;

                    largest=DFS(grid,i,j,visited);
                    
                    
                    
                    maxArea = max(maxArea, largest);
                    grid[i][j] = 0; 
                }
            }
        }
        
        return (maxArea == 0) ? m * n : maxArea; 
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};


//Approach - 3  - Optimal DFS 
//T.C : O(m*n)
//S.C : O(m*n)

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int DFS(vector<vector<int>>& grid, int i, int j,int id) {

        
        if(i < 0 || i >= m || j < 0 || j >= n || grid[i][j] != 1){
            return 0;
        }
        grid[i][j]=id;
        int count = 1;

        for(vector<int>& dir : directions) {
            count += DFS(grid, i + dir[0], j + dir[1],id);
        }

        return count;
    }

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;

        unordered_map<int,int>mp;
        int id=2;
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                
                if(grid[i][j]==1)
                {
                    int size = DFS(grid,i,j,id);
                    maxArea=max(maxArea,size);
                    mp[id]=size;
                    id++;
                    
                }
            }
        }

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0) { 
                    unordered_set<int>st;
                    for(auto &dir : directions)
                    {
                        int new_i=dir[0]+i;
                        int new_j=dir[1]+j;
                        if(new_i>=0&&new_i<m&&new_j>=0&&new_j<n&& grid[new_i][new_j]!=0)
                        {
                            st.insert(grid[new_i][new_j]);
                            
                        }
                    }
                    int sum=1;//uss node ka size one hai toh
                    for(const int &s:st)
                    {
                        sum+=mp[s];
                    }

                    maxArea=max(maxArea,sum);

                 
                }
            }
        }
        
        return maxArea; 
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};

//Approach-4 (Using DSU)
//T.C : O(m*n * alpha(m*n))
//S.C : O(m*n)
class dsu {
public:
    vector<int> parent;
    vector<int> size;

    dsu(int n) {
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) {
            parent[i] = i;
        }
    }

    int find(int x) {
        if (parent[x] == x) return x;
        return parent[x] = find(parent[x]);
    }

    void Union(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY) return;

        if (size[rootX] > size[rootY]) {
            parent[rootY] = rootX;
            size[rootX] += size[rootY];
        } else {
            parent[rootX] = rootY;
            size[rootY] += size[rootX];
        }
    }

    int getSize(int x) {
        return size[find(x)];
    }
};

class Solution {
public:
    int m, n;
    vector<vector<int>> directions{{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

    int findLargestIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int totalCells = m * n;  
        dsu dsu(totalCells);
        int maxArea = 0;

        
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    int idx = i * n + j;
                    for (auto& dir : directions) {
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
                            int new_idx = new_i * n + new_j;
                            dsu.Union(idx, new_idx);
                        }
                    }
                }
            }
        }

        
        for (int idx = 0; idx < totalCells; idx++) {
            int i = idx / n, j = idx % n;
            if (grid[i][j] == 1) {
                maxArea = max(maxArea, dsu.getSize(idx));
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) {
                    unordered_set<int> up;
                    for (auto& dir : directions) {
                        int new_i = i + dir[0];
                        int new_j = j + dir[1];

                        if (new_i >= 0 && new_i < m && new_j >= 0 && new_j < n && grid[new_i][new_j] == 1) {
                            up.insert(dsu.find(new_i * n + new_j));
                        }
                    }

                    int newSize = 1;
                    for (int parent : up) {
                        newSize += dsu.getSize(parent);
                    }
                    maxArea = max(maxArea, newSize);
                }
            }
        }

        return maxArea;
    }

    int largestIsland(vector<vector<int>>& grid) {
        return findLargestIsland(grid);
    }
};
