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
    
    
        int dp[51][51][101];
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
    
            if(dp[idx][sc][max] != -1)
            {
                return dp[idx][sc][max];
            }
    
            int result=0;
            for(int i= 1;i<=M;i++)
            {
                if(i>max)
                {
                    result = (result+recur(idx+1,sc+1,i)) % mod;
                }
                else{
                    result = (result+recur(idx+1,sc,max)) % mod;
                }
            }
            return dp[idx][sc][max]=result % mod;
    
    
        }
        
        int numOfArrays(int n, int m, int k) {
    
            N=n;
            M=m;
            K=k;
            memset(dp,-1,sizeof(dp));
            return recur(0,0,0);
    
        }
    };

