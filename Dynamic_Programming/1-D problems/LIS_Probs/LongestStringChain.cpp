
#include<iostream>
using namespace std;


//Recursion and memo
class Solution {
    public:
        int n;
    
        int t[1001][1001];
        bool issubsequence(string &a,string &b)
        {
            int M=a.length();
            int N=b.length();
            if((N-M)!=1 || M>=N )
            {
                return false;
            }
            int i=0;
            int j=0;
            while(i<M && j<N)
            {
                if(a[i]==b[j])
                {
                    i++;
                }
                j++;
            }
            return i==M; 
    
        }
    
        static bool myfunction( string &word1,string &word2 )
        {
            return word1.length()<word2.length();
        }
    
        int recur(int i,int prev,vector<string>& words)
        {
            if(i>=n)
            {
                return 0;
            }
            if(prev!=-1 && t[i][prev]!=-1)
            {
                return t[i][prev];
            }
    
            int skip=recur(i+1,prev,words);
    
            int take=0;
            if(prev==-1 || issubsequence(words[prev],words[i]) )
            {
                take=1+recur(i+1,i,words);
            }
    
            if(prev!=-1)
            {
                t[i][prev]=max(take,skip);
            }
    
            return max(take,skip);
        }
    
    
        int longestStrChain(vector<string>& words) {
    
            int prev=-1;
    
            sort(begin(words),end(words),myfunction);
            n=words.size();
            memset(t,-1,sizeof(t));
    
            return recur(0,prev,words);
        }
    };


// bottom up approach

class Solution {
public:
   int n;
   bool issubsequence(string &a,string &b)
        {
            int M=a.length();
            int N=b.length();
            if((N-M)!=1 || M>=N )
            {
                return false;
            }
            int i=0;
            int j=0;
            while(i<M && j<N)
            {
                if(a[i]==b[j])
                {
                    i++;
                }
                j++;
            }
            return i==M; 
    
        }
    
        static bool myfunction( string &word1,string &word2 )
        {
            return word1.length()<word2.length();
        }
    int longestStrChain(vector<string>& words) {

        n=words.size();

        sort(begin(words),end(words),myfunction);

        vector<int>t(n,1);

        int maxl=1;
        
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(issubsequence(words[j],words[i]))
                {
                    t[i]=max(t[i],t[j]+1);
                    maxl=max(maxl,t[i]);
                }
            }
        }

        return maxl;
        
    }
};

