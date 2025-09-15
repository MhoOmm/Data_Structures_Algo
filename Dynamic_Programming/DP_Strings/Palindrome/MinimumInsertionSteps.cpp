#include<iostream>
using namespace std;

//recur+memoization
class Solution {
    public:
    
        int n;
    
        int t[501][501];
    
        int recur(string &s,int i,int j)
        {
            if(i>=j)return 0;
    
            if(t[i][j]!=-1)
            {
                return t[i][j];
            }
            if(s[i]==s[j])
            {
                return t[i][j]=recur(s,i+1,j-1);
            }else{
                return t[i][j]=1+min(recur(s,i,j-1),recur(s,i+1,j));
            }
        }
        int minInsertions(string s) {
            n=s.length();
            memset(t,-1,sizeof(t));
            return recur(s,0,n-1);
        }
    };


//bottom up approach

class Solution {
    public:
        int minInsertions(string s) {
    
            int n=s.length();
            vector<vector<int>>t(n+1,vector<int>(n+1));
    
            for(int i=0;i<n;i++)
            {
                t[i][i]=0;
            }
    
            for(int l=2;l<=n+1;l++)
            {
                for(int i=0;i<n-l+1;i++)
                {
                    int j=i+l-1;
                    if(s[i]==s[j])
                    {
                        t[i][j]=t[i+1][j-1];
                    }else{
    
                        t[i][j]= 1+ min(t[i+1][j],t[i][j-1]);
                    }
                }
            }
    
            return t[0][n-1];
            
        }
    };

