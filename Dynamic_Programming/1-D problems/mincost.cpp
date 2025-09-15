#include<iostream>
using namespace std;

// recursive solution d
class Solution {
public:
    int ways(vector<int>&cost,int n)
    {
        if(n<=1)
        {
            return 0;
        }
        return min((cost[n-1]+ways(cost,n-1)),(cost[n-2]+ways(cost,n-2)))
    }
    int minCostClimbingStairs(vector<int>& cost) {
            int  n= cost.size();
            return count(cost,n)
    }
};

//memoization and top down approach
class Solution {
public:
    int ways(vector<int>&cost,vector<int>&dp,int n)
    {
        if(n<=1)
        {
            return 0;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return  dp[n]=min((cost[n-1]+ways(cost,dp,n-1)),(cost[n-2]+ways(cost,dp,n-2)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
            int  n= cost.size();
            vector<int>dp(n+1,-1);
            return ways(cost,dp,n);
    }
};

// bottom up approach

class Solution {
public:
    int ways(vector<int>&cost,vector<int>&dp,int n)
    {
        dp[0]=0;
        dp[1]=0;
        for(int i=2;i<=n;i++)
        {
            dp[i]=min((cost[i-1]+dp[i-1]),(cost[i-2]+dp[i-2]));
        }
        return dp[n]; 
    }
    int minCostClimbingStairs(vector<int>& cost) {
            int  n= cost.size();
            vector<int>dp(n+1,-1);
            return ways(cost,dp,n);
    }
};


// OPTMIZATION
// bottom up approach

class Solution {
public:
    int ways(vector<int>&cost,int n)
    {
        int prev=0;
        int prev2=0;
        int curr=0;
        for(int i=2;i<=n;i++)
        {
            curr=min((cost[i-1]+prev),(cost[i-2]+prev2));
            prev2=prev;
            prev=curr;
        }
        return curr; 
    }
    int minCostClimbingStairs(vector<int>& cost) {
            int  n= cost.size();
            return ways(cost,n);
    }
};

// alternate approach

//recursion
//recursion
class Solution {
public:
    int ways(vector<int>&cost,int n,int i)
    {
        if(i>=n)
        {
            return 0;
        }
        return min((cost[i]+ways(cost,n,i+1)),(cost[i]+ways(cost,n,i+2)));
    }
    int minCostClimbingStairs(vector<int>& cost) {
            int  n= cost.size();
            int i=0;
            return min(ways(cost,n,0),ways(cost,n,1));
    }
};
