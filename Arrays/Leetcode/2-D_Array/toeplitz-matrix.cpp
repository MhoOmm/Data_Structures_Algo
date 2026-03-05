// simple dfs approach

class Solution {
public:
    int n,m;
    bool dfs(int num,int i,int j,vector<vector<int>>& matrix)
    {
        if(i>=m || j>=n) return true; //correct till now;
        if(matrix[i][j]!=num)
        {
            return false;
        }
        return dfs(num,i+1,j+1,matrix);
    }
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        m = matrix.size();
        n = matrix[0].size();

        for(int i=0;i<m;i++)
        {
            if(!dfs(matrix[i][0],i+1,1,matrix))
            {
                return false;
            }
        }
        for(int j=1;j<n;j++)
        {
            if(!dfs(matrix[0][j],1,1+j,matrix))
            {
                return false;
            }
        }

        return true;
    }
};

// 2-D traverse

class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i-1][j-1]!=matrix[i][j])
                {
                    return false;
                }
            }   
        }

        return true;
    }
};