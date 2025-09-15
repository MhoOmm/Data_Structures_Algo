#include<iostream>
using namespace std;


// recur + memo through lcs
class Solution {
    public:
    
        int t[1001][1001];
    
        int recur(string &s1,string &s2,int i, int j)
        {
            if(i>=s1.length() || j>=s2.length())
            {
                return 0;
            }
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            if(s1[i]==s2[j])
            {
                return t[i][j]=1+recur(s1,s2,i+1,j+1);
            }else{
                return t[i][j]=max(recur(s1,s2,i,j+1),recur(s1,s2,i+1,j));
            }
    
        }
        int longestPalindromeSubseq(string s) {
    
            int n=s.length();
            memset(t,-1,sizeof(t));
    
            string s1=s;
            string s2 = s;
            reverse(s2.begin(), s2.end());
    
            return recur(s1,s2,0,0);
        }
    };


// bottom up through lcs
class Solution {
    public:
        int longestPalindromeSubseq(string s) {
    
            string s1=s;
            string s2=s;
            reverse(s2.begin(),s2.end());
            
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
                for(int j=1;j<n+1;j++){
    
                    if(s1[i-1]==s2[j-1])
                    {
                        t[i][j]=1+ t[i-1][j-1];
                    }
                    else{
                        t[i][j]=max(t[i-1][j],t[i][j-1]);
                    }
    
                }
            }
    
            return t[m][n];
            
        }
    };

// without using lcs
// recur+ memoiztion

class Solution {
    public:
    
        int n;
        int t[1001][1001];
    
        int recur(string &s,int i,int j)
        {
            if(i>j)
            {
                return 0;
            }
    
            if(i==j) return 1;
    
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
    
            if(s[i]==s[j])
            {
                return t[i][j]=2+recur(s,i+1,j-1);
            }else{
                return t[i][j]=max(recur(s,i+1,j),recur(s,i,j-1));
            }
        }
    
    
        int longestPalindromeSubseq(string s) {
    
            memset(t,-1,sizeof(t));
            n= s.length();
            return recur(s,0,n-1);
        }
    };


// bottom up using blurprint


class Solution {
    public:
        int longestPalindromeSubseq(string s) {
    
            int n=s.length();
    
            vector<vector<int>>t(n,vector<int>(n));
            for(int i=0;i<n;i++)
            {
                t[i][i]=1;// 1-length substring
            }
    
            for(int l=2;l<=n;l++)
            {
                for(int i=0;i<n-l+1;i++)
                {
                    int j=i+l-1;
                    if(s[i]==s[j])
                    {
                        t[i][j]=2+t[i+1][j-1];
    
                    }
                    else{
                        t[i][j]=max(t[i][j-1],t[i+1][j]);
                    }
                }
            }
    
            return t[0][n-1];
    
            
        }
    };

