//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

//recursion and memoization approach

class Solution {
  public:
    // Function to find length of shortest common supersequence of two strings.
    
    int dp[501][501];
    
    int recurr(string &s1,string &s2,int i,int j)
    {
        if(i == s1.length())//base case
        {
            return s2.length() - j;
        }
        else if(j==s2.length())
        {
            return s1.length()-i;
            
        }
        if(dp[i][j]!=-1)
        {
            return dp[i][j];
        }
        
        if(s1[i]==s2[j])
        {
            return dp[i][j]=1+recurr(s1,s2,i+1,j+1);
        }
        else{
            return dp[i][j]=1+ min(recurr(s1,s2,i+1,j),recurr(s1,s2,i,j+1));
        }
    }
    int shortestCommonSupersequence(string &s1, string &s2) {
        // code here
        
        memset(dp,-1,sizeof(dp));
        return recurr(s1,s2,0,0);
    }
};



//the same above code but from back perspective

int recurr(string &s1,string &s2,int m,int n)
{
    // base case
    if(m==0)return n;

    else if(n==0)return m;

    if(s1[m-1]==s2[n-1])
    {
        return 1+recurr(s1,s2,m-1,n-1);
    }
    else{
        return 1+ min(recurr(s1,s2,m-1,n),recurr(s1,s2,m,n-1));
    }

}
int shortestCommonSupersequence(string &s1, string &s2) {
    // code here
    
    memset(dp,-1,sizeof(dp));
    int m=s1.length();
    int n=s2.length();
    return recurr(s1,s2,m,n);
}






// bottom up approach


class Solution {
    public:
      // Function to find length of shortest common supersequence of two strings.
      int shortestCommonSupersequence(string &s1, string &s2) {
          
          int m=s1.length();
          int n=s2.length();
          
          vector<vector<int>> t(m+1,vector<int>(n+1));
          
          for(int i=0;i<m+1;i++)
          {
              for(int j=0;j<n+1;j++)
              {
                  if(i==0||j==0)
                  {
                      t[i][j]=i+j;
                  }
                  else if(s1[i-1]==s2[j-1])
                  {
                      t[i][j]=1+t[i-1][j-1];
                  }
                  else{
                      t[i][j]=1+min(t[i-1][j],t[i][j-1]);
                  }
              }
          }
          return t[m][n];
      }
  };


//3rd approach-using lcs 

// dono ka lcs nikalo aur uska length ko dono ke length ke sum se minus kardo
class Solution {
    public:
      // Function to find length of shortest common supersequence of two strings.
      int shortestCommonSupersequence(string &s1, string &s2) {
          
          int m=s1.length();
          int n=s2.length();
      
          vector<vector<int>>t(m+1,vector<int>(n+1));
      
      
          for(int row=0;row<m+1;row++)
              {
                  t[row][0]=0;
              }
              for(int col=0;col<n+1;col++)
              {
                  t[0][col]=0;
              }
      
      
          for(int i=1;i<m+1;i++)
          {
              for(int j=1;j<n+1;j++)
              {
                  if(s1[i-1]==s2[j-1])
                  {
                      t[i][j]=1+t[i-1][j-1];
                  }else{
                      t[i][j]=max(t[i-1][j],t[i][j-1]);
                  }
      
              }
          }
          
          int l=(m+n)-t[m][n];
          
          return l;
      }
  };


  

//{ Driver Code Starts.

int main() {

    int t;

    // taking total testcases
    cin >> t;
    while (t--) {
        string X, Y;
        // taking String X and Y
        cin >> X >> Y;

        // calling function shortestCommonSupersequence()
        Solution obj;
        cout << obj.shortestCommonSupersequence(X, Y) << endl;
    }
    return 0;
}

// } Driver Code Ends