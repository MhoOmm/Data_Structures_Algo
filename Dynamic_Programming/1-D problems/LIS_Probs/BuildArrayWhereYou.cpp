#include<iostream>
using namespace std;

//recursion solution
class Solution {
    public:
    
    
        // int dp[][][]
        int N,M,K;
    
    
        int recur(int idx,int sc,int max)
        {
            int mod =1e9+7;
            
            if(idx==N)//base case
            {
                if(sc==K)
                {
                    return 1;
                }
                else{
                    return 0;
                }
            }
    
            int result=0;
            for(int i= 1;i<=M;i++)
            {
                if(i>max)
                {
                    result+=(recur(idx+1,sc+1,i))%mod;
                }
                else{
                    result+=(recur(idx+1,sc,max))%mod;
                }
            }
            return result % mod;
    
    
        }
        
        int numOfArrays(int n, int m, int k) {
    
            N=n;
            M=m;
            K=k;
            return recur(0,0,-1);
    
        }
    };
// memoization

class Solution {
public:
    int n,m,k;
    int t[51][51][102];
    int mod =1e9+7;
    int solve(int idx , int sc, int max)
    {
        if(idx==n)
        {
            if(sc==k)
            {
                return 1;
            }else{
                return 0;
            }

        }
        if(t[idx][sc][max+1]!=-1)
        {
            return t[idx][sc][max+1];
        }

        long long res = 0;
        for(int i=1;i<=m;i++)
        {
           if(i>max)
           {
            res += (solve(idx+1,sc+1,i))%mod;
           }else{
            res += (solve(idx+1,sc,max))%mod;
           }
        }

        return t[idx][sc][max+1] = res%mod;
    }
    int numOfArrays(int N, int M, int K) {
       n=N;
       m=M;
       k=K;
       memset(t,-1,sizeof(t));
       return solve(0,0,-1);  
    }
};



