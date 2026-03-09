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
    int t[46];
    int solve(int num,int n)
    {
        if(num==n)
        {
            return 1;
        }
        if(num>n)
        {
            return 0;
        }
        if(t[num]!=-1)
        {
            return t[num];
        }

        return t[num] = solve(num+1,n)+solve(num+2,n);
    }
    int climbStairs(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,n);
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
    int climbStairs(int n) {
        vector<int>t(n+1,-1);
        if(n<=2)
        {
            return n;
        }
        t[1] = 1;
        t[2] = 2;



        for(int i=3;i<=n;i++)
        {
            t[i] = t[i-1]+t[i-2];
        }

        return t[n];

    }
};







int main()
{
    
    return 0;
}