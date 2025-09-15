class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        vector<vector<int>>temp=matrix;

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    for(int k=0;k<n;k++)
                    {
                        temp[i][k]=0;
                    }
                    for(int k=0;k<m;k++)
                    {
                        temp[k][j]=0;
                    }
                }
            }
        }
        matrix=temp;
    }
};


class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();
        vector<bool>row(m,false);
        vector<bool>col(n,false);

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                  row[i]=true;
                  col[j]=true;
                }
            }
        }
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(row[i]==true || col[j]==true)
                {
                    matrix[i][j]=0;
                }
            }
        }
    }
};
//in place solution
class Solution {
public:
    
    void setZeroes(vector<vector<int>>& matrix) {
        int m=matrix.size();
        int n=matrix[0].size();

        bool firstrow=false;
        for(int i=0;i<n;i++)
        {
            if(matrix[0][i]==0)
            {
                firstrow=true;
            }
        }
        bool firstcol=false;
        for(int i=0;i<m;i++)
        {
            if(matrix[i][0]==0)
            {
                firstcol=true;
            }
        }

        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }
        
        for(int i=1;i<m;i++)
        {
            for(int j=1;j<n;j++)
            {
                if(matrix[i][0]==0||matrix[0][j]==0)
                {
                    matrix[i][j]=0;
                }
            }
        }
        if(firstrow)
        {
            for(int i=0;i<n;i++)
            {
                matrix[0][i]=0;
            }
        }
        if(firstcol)
        {
            for(int i=0;i<m;i++)
            {
                matrix[i][0]=0;
            }
        }

        
    }
};