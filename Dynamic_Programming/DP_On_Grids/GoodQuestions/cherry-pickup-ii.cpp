class Solution {
public:
    int m,n;
    int t[71][71][71];
    int solve(vector<vector<int>>& grid,int r1,int c1,int c2)
    {
        if(r1<0 || r1>=m || c1<0 || c1>=n || c2<0 || c2>=n)
        {
            return INT_MIN;
        }

        if(t[r1][c1][c2]!=INT_MIN)
        {
            return t[r1][c1][c2]; 
        }
        // there are total 9 possibilities
        int currSum;
        if(c1 == c2){
            // if they are on same block->count once
            currSum = grid[r1][c1];
        }
        else{
            currSum = grid[r1][c1] + grid[r1][c2];
        }
        if(r1==m-1) 
        {
            return currSum;
        }
        int next = INT_MIN;
        for(int dif = -1;dif<=1;dif++)
        {
            for(int indif=-1;indif<=1;indif++)
            {
                int nr = r1+1;
                int nc1 = c1+dif;
                int nc2 = c2+indif;
                next = max(next,solve(grid,nr,nc1,nc2));
            }
        }
        if(next!=INT_MIN)
        {
            currSum += next;
        }
        return t[r1][c1][c2] = currSum;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        for(int i=0;i<71;i++)
        {
            for(int j=0;j<71;j++)
            {
                for(int k=0;k<71;k++)
                {
                    t[i][j][k] = INT_MIN;
                }
            }
        }
        return solve(grid,0,0,n-1);// row,col1,col2
    }
};