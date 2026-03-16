
#include<iostream>
using namespace std;


//Recursion and memo
class Solution {
public:
    int t[1001][1001];
    bool isPred(string s1,string s2)
    {
        int m = s1.length();
        int n = s2.length();

        if(m>=n || (n-m!=1))
        {
            return false;
        }

        int i=0;
        int j=0;

        while(i<m && j<n)
        {
            if(s1[i]==s2[j])
            {
                i++;
            }
            j++;
        }
        return i==m;
    }
    int solve(vector<string>& words,int i,int prev)
    {
        if(i>=words.size())
        {
            return 0;
        }

        if(t[i][prev+1]!=-1)
        {
            return t[i][prev+1];
        }

        int skip = solve(words,i+1,prev);
        int take = 0;
        if( prev==-1 || isPred(words[prev],words[i]))
        {
            take = 1+ solve(words,i+1,i);
        }

        return t[i][prev+1] = max(take,skip);
    }
    int longestStrChain(vector<string>& words) {
        memset(t,-1,sizeof(t));
        sort(words.begin(),words.end(),[](string &a, string &b){
            return a.length()<b.length();
        });
        return solve(words,0,-1);
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

