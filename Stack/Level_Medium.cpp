#include <iostream>
#include <stack>
#include<vector>
using namespace std;
//FUNCTION TO FIND THE NEXT GREATER ELEMENT OF A ELMENT IN ARRAY 
//AND TO STORE IN A ANOTHER ARRAY O(n)

vector<int> nextgreater(vector<int>arr,int n)
{
    vector<int>ans(n,-1);
    stack<int>s;
    for ( int i=0;i<n;i++)
    {
        while( !s.empty()&& arr[s.top()<arr[i]])
        {
            ans[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
}

//FUNCTION TO FIND THE SMALLER ELEMENT

vector<int> nextsmaller(vector<int>arr,int n)
{
    vector<int>ans(n,-1);
    stack<int>s;
    for ( int i=0;i<n;i++)
    {
        while( !s.empty()&& arr[s.top()>arr[i]])
        {
            ans[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
}

//FUNCTION TO FIND THE SMALLEST ELEMENT ON THE LEFT
vector<int> smallestatleft(vector<int>arr,int n)
{
    vector<int>ans(n,-1);
    stack<int>s;
    for ( int i=n;i>=0;i--)
    {
        while( !s.empty()&& arr[s.top()]>arr[i])
        {
            ans[s.top()]=arr[i];
            s.pop();
        }
        s.push(i);
    }
}
// Function for stock span problem.this provides for a element 
// how many elements are smaller than this one
vector<int> stockspan(vector<int>arr,int n)
{
    vector<int>ans(n,-1);
    stack<int>s;
    for ( int i=n;i>=0;i--)
    {
        while( !s.empty()&& arr[i]>arr[s.top()])
        {
            ans[s.top()]=s.top()-i;
            s.pop();
        }
        s.push(i);
    }
    while(!s.empty())
    {
        ans[s.top()]=s.top()+1;
        s.pop();
    }
    return ans;
} 


int main ()
{

}





