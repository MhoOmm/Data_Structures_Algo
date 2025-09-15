#include<iostream>
using namespace std;

// recurr and memoization
class Solution {
    public:
    
        int t[501][501];
        int  recur(string &s1,string &s2,int i ,int j)
        {
            int m=s1.length();
            int n=s2.length();
    
            if(i==m)return n-j;
    
            if(j==n)return m-i;
    
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
    
            if(s1[i]==s2[j])
            {
                return t[i][j]=recur(s1,s2,i+1,j+1);
            }

            else{
                int insert=1+recur(s1,s2,i,j+1);
                int del=1+recur(s1,s2,i+1,j);
                int update=1+recur(s1,s2,i+1,j+1);
    
                return t[i][j] = min({insert,del,update});
            }
            
        }
        int minDistance(string s1, string s2) {
    
            memset(t,-1,sizeof(t));
    
            return recur(s1,s2,0,0);
    
            
        }
    };


// same code but backwards

class Solution {
    public:
    
        int t[501][501];
        int  recur(string &s1,string &s2,int m,int n)
        {
            
    
            if(m==0)return n;
    
            if(n==0)return m;
    
            if(t[m][n]!=-1)
            {
                return t[m][n];
            }
    
            if(s1[m-1]==s2[n-1])
            {
                return t[m][n]=recur(s1,s2,m-1,n-1);
            }
            else{
                int insert=1+recur(s1,s2,m,n-1);
                int del=1+recur(s1,s2,m-1,n);
                int update=1+recur(s1,s2,m-1,n-1);
        
                return t[m][n] = min({insert,del,update});

            }
          
        }
        int minDistance(string s1, string s2) {
    
            memset(t,-1,sizeof(t));
    
            int m=s1.length();
            int n=s2.length();
    
            return recur(s1,s2,m,n);
    
            
        }
    };


// bottom up approach

class Solution {
    public:
        int minDistance(string s1, string s2) {
    
            int m=s1.length();
            int n=s2.length();
    
            vector<vector<int>>t (m+1,vector<int>(n+1));
    
            for (int i = 0; i <= m; i++) t[i][0] = i;
            for (int j = 0; j <= n; j++) t[0][j] = j;
    
            for(int i=1;i<m+1;i++)
            {
                for(int j=1;j<n+1;j++)
                {
                    if(s1[i-1]==s2[j-1])
                    {
                        t[i][j]=t[i-1][j-1];
                    }
                    else{
                        int insert=1+t[i][j-1];
                        int del=1+t[i-1][j];
                        int update=1+t[i-1][j-1];
    
                        t[i][j]=min({insert,del,update});
                    }
                }
            }
    
            return t[m][n];
            
        }
    };