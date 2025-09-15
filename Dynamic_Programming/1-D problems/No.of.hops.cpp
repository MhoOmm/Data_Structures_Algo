#include<iostream>
using namespace std;

// recursive solution 
class Solution {
  public:

    int count(int i,int n){
        if(i==n)
        return 1;
        
        if(i>n)
        return 0;
        
        return count(i+1,n) + count(i+2,n) + count(i+3,n);
    }
    int countWays(int n) {

        // your code here
        return count(0,n);
    }
};


int main()
{
    
    return 0;
}