// recursion + memo
class Solution {
public:
    int n, m;
    int t[101][101][201];
    bool solve(int i, int j, int count, vector<vector<char>>& grid)
    {
        // out of bound
        if(i >= n || j >= m)
        {
            return false;
        }
        if(grid[i][j] == '(')
        {
            count++;
        }
        else
        {
            count--;
        }
        // invalid path
        if(count < 0)
        {
            return false;
        }
        if(t[i][j][count] != -1)
        {
            return t[i][j][count];
        }
        if(i==n-1 && j==m-1)
        {
            return t[i][j][count] = (count == 0);
        }
        // down
        bool down = solve(i + 1, j, count, grid);
        // right
        bool right = solve(i, j + 1, count, grid);
        return t[i][j][count] = (down || right);
    }

    bool hasValidPath(vector<vector<char>>& grid)
    {
        n = grid.size();
        m = grid[0].size();
        memset(t, -1, sizeof(t));
        return solve(0, 0, 0, grid);
    }
};

// small optimisation -> count the remaining cells 
//  if count > remaining cells then ) cant cover all ( braces

int rem = (n - 1 - i) + (m - 1 - j);
if(count > rem)
{
    return false;
}