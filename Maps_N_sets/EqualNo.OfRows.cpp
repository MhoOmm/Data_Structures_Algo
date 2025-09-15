class Solution {
public:
    int equalPairs(vector<vector<int>>& grid) {
        int n=grid.size();
        map<vector<int>,int >mp;
        int count=0;
        for(int r=0;r<n;r++)
        {
            mp[grid[r]]++;
        }
        for(int c=0;c<n;c++)
        {
            vector<int>temp;
            for(int r=0;r<n;r++)
            {
                temp.push_back(grid[r][c]);
            }
            count+=mp[temp];
        }

        return count;
    }
};