#include<iostream>
using namespace std;
#include <vector>

// brute froce recursion approach
// tc : o(2^n)
// sc : o(2^n)
class Solution {
public:
    int count(int n,int k)
    {
        if(n==k)
        {
            return 1;
        }
        if(k>n){
            return 0;
        }
        return count(n,k+1)+count(n,k+2);

    }
    int climbStairs(int n) {
        int i=0;
        return count(n,i);
    }
};

// memoization - topdown approach
// tc : o(n)
// sc : o(n)

class Solution {
public:
    int count(int n,int k,vector<int>&dp)
    {
        if(n==k)
        {
            return 1;
        }
        if(k>n)
        {
            return 0;
        }
        if(dp[k] != -1)
        {
            return dp[k];
        }
        return dp[k]=count(n,k+1,dp)+count(n,k+2,dp);

    }
    int climbStairs(int n) {
        int i=0;
        vector<int>dp(n+2,-1);
        return count(n,i,dp);
    }
};

// bottom-up approach
// tc : o(n)
// sc : o(n)
class Solution {
public:
    int count(int n,int k,vector<int>&dp)
    {
        dp[n+1]=0;
        dp[n]=1;
        for(int i=n-1;i>=0;i--)
        {
            dp[i]=dp[i+1]+dp[i+2];
        }
        return dp[0];

    }
    int climbStairs(int n) {
        int i=0;
        vector<int>dp(n+2,-1);
        return count(n,i,dp);
    }
};

// optimised approach
// tc : o(n)
// sc : o(1)

class Solution {
public:
    int count(int n,int k,vector<int>&dp)
    {
        int after=1;
        int after2=0;
        int curr=0;
        for(int i=n-1;i>=0;i--)
        {
            curr=after+after2;
            after2=after;
            after=curr;
            
        }
        return curr;

    }
    int climbStairs(int n) {
        int i=0;
        vector<int>dp(n+2,-1);
        return count(n,i,dp);
    }
};







int main()
{
    
    return 0;
}