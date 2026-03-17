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
    int mod = 1e9 + 7;
    int t[51][51][102];
    int solve(int n,int m,int k, int i,int sc,int maxele)
    {
        if(sc > k) return 0;
        if(i>=n)
        {
            if(sc==k)
            {
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][sc][maxele+1] !=-1)
        {
            return t[i][sc][maxele+1];
        }
        long long ans = 0;
        for(int j=1;j<=m;j++)
        {
            if(j>maxele)
            {
                ans += solve(n,m,k,i+1,sc+1,j)%mod;
            }
            else{
                ans += solve(n,m,k,i+1,sc,maxele)%mod;
            }
        }

        return t[i][sc][maxele+1] = ans%mod;
    }
    int numOfArrays(int n, int m, int k) {

        memset(t,-1,sizeof(t));

        //                 i,sc,maxele
        return solve(n,m,k,0,0,-1);
        
    }
};


