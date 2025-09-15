#include <iostream>
using namespace std;
bool bs(int arr[],int start,int end,int x)
{
    if(start>end)
    {
        return 0;
    }
    int mid=(start+end)/2;
    if(arr[mid]==x)
    {
        return 1;
    }
    else if(arr[mid]<x)
    {
        return bs(arr,mid+1,end,x);
    }
    else
    {
        return bs(arr,start,mid-1,x);
    }
}
int main ()
{
    int arr[100];
    int n,x,i;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter the elemenst of the array:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"enter the element your want to search:";
    cin>>x;
    int start=0;
    int end=n-1;
    cout<<bs(arr,start,end,x);
    
}