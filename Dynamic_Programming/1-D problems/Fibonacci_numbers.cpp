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

class Solution {
public:
    int fib(int n) {
        vector<int>t(n+1,-1);
        if(n<=1)return n;
        t[0] = 0;
        t[1] = 1;

        for(int i=2;i<=n;i++)
        {
            t[i] = t[i-1]+t[i-2];
        }

        return t[n];
    }
};

//bottom up approach
//tc : o(n)
//sc : o(n)

class Solution {
public:
    int fib(int n) {
        vector<int>t(n+1,-1);
        if(n<=1)return n;
        t[0] = 0;
        t[1] = 1;

        for(int i=2;i<=n;i++)
        {
            t[i] = t[i-1]+t[i-2];
        }

        return t[n];
    }
};
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
