class Solution {
public:
    int N;
    vector<vector<int>>directions={{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};
    double t[26][26][101];
    double solve(int row,int col,int k,int n)
    {
        if(row>=n || col>=n || row<0 || col<0){// out of bounds 
            return 0;
        }
        if(t[row][col][k]!=-1)
        {
            return t[row][col][k];
        }
        if(k==0)//idhar aagya hai to within bounds
        {
            return 1;
        }
        double result = 0;
        for(auto &dir:directions)
        {
            int ni = row +dir[0];
            int nj = col +dir[1];
            result += solve(ni,nj,k-1,n);
        }
        return t[row][col][k] = result;
    }
    double knightProbability(int n, int k, int row, int column) {
        N = n;
        for(int i=0;i<26;i++){
            for(int j=0;j<26;j++){
                for(int k=0;k<101;k++){
                    t[i][j][k] = -1.0;
                }
            }
        }
        return solve(row,column,k,N)/pow(8,k);
    }
};