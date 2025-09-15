#include<iostream>
using namespace std;
#include<vector>


// normal approach 
// tc: o(2^n)
// sc: o(2^n)
 
class solution{
    int fib(int n){
        if(n<=1)
        {
            return n;

        }
        fib(n)=fib(n-1)+fib(n-2);
    }
};

//top down approach
//tc : o(n)
//sc : o(n)

class solution{

    int fibon(vector<int>&dp, int n)
    {
        if(n<=1)
        {
            return n;
        }
        if(dp[n]!=-1)
        {
            return dp[n];
        }
        return fibon(dp,n-1)+ fibon(dp,n-2);
    }

    int fib(int n){
        vector<int>dp(n+1,-1);
        return fibon(dp,n);

    }
};

//bottom up approach
//tc : o(n)
//sc : o(n)

class solution{
    int fib(int n)
    {
        // first figure out the base cases and then act upon it

        if(n<=1)
        {
            return n;
        }

        vector<int>dp(n+1,-1);
        dp[0]=0;
        dp[1]=1;
        for(int i=2;i<n;i++)
            {
                dp[i]=dp[i-1]+dp[i-2];
            }
        return dp[n];

        
    }
}

// optimization
//only using three variable

// tc = o(n)
// sc = o(1)

class solution{

    int fib(int n)
    {
        int prev=0;
        int prev2=1;
        int curr=0;

        if(n==0)
        {
            return prev;
        }
        if(n==1)
        {
            return prev2;
        }
        for( int i=2;i<=n;i++)
        {
            curr=prev+prev2;
            prev2=prev;
            prev =curr;
        }
        return curr;

    }

};


int main()
{
    
    return 0;
}
