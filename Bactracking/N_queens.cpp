#include<iostream>
using namespace std;
#include<vector>


class Solution {
public:

    // to check both the diagonals
    bool check(int n,vector<string>Board,int i,int j)
    {
        int row=i,col=j;
        while(row>-1 && col>-1)
        {
            if (Board[row][col]=='Q')
            {
                return 0;
            }
            row--;
            col--;
        }

        row =i;
        col=j;
        while(row>-1 && col<n)
        {
            if (Board[row][col]=='Q')
            {
                return 0;
            }
            row--;
            col++;
        }
        return 1;

    }
    void nqueens(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>col)
    {
        //base case

        if (row==n)
        {
            ans.push_back(Board);
            return;
        }

        // checking condition to enter queen
        for (int j=0;j<n;j++)
        {
            if (col[j]==0 && check(n,Board,row,j))
            {
                col[j]=1;
                Board[row][j]='Q';
                nqueens(row+1,n,ans,Board,col);
                col[j]=0;
                Board[row][j]='.';
            }
        }
    
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i =0 ;i<n ;i++)
        {
            for ( int j=0;j<n;j++)
            {
                Board[i].push_back('.');
            }
        }

        vector<bool>col(n,0);

        nqueens(0,n,ans,Board,col);

        return ans ;

        
        
    }
};




// more optimized
class Solution2 {
public:

    
    void nqueens(int row,int n,vector<vector<string>>&ans,vector<string>&Board,vector<bool>col,vector<bool>leftdig,vector<bool>rightdig)
    {
        //base case

        if (row==n)
        {
            ans.push_back(Board);
            return;
        }

        // checking condition to enter queen
        for (int j=0;j<n;j++)
        {
            if (col[j]==0 && rightdig[row+j]==0 && leftdig[(j-row)+(n-1)]==0 )
            {
                col[j]=1;
                Board[row][j]='Q';
                rightdig[row+j]=1;
                leftdig[(j-row)+(n-1)]=1;
                nqueens(row+1,n,ans,Board,col,leftdig,rightdig);
                col[j]=0;
                Board[row][j]='.';
                rightdig[row+j]=0;
                leftdig[(j-row)+(n-1)]=0;
            }
        }
    
    }
    vector<vector<string>> solveNQueens(int n) {

        vector<vector<string>>ans;
        vector<string>Board(n);
        for(int i =0 ;i<n ;i++)
        {
            for ( int j=0;j<n;j++)
            {
                Board[i].push_back('.');
            }
        }

        vector<bool>col(n,0);
        vector<bool>leftdig(2*n-1,0);
        vector<bool>rightdig(2*n-1,0);

        nqueens(0,n,ans,Board,col,leftdig,rightdig);

        return ans ;

        
        
    }
};