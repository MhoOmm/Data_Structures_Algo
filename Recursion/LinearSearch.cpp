#include <iostream>
using namespace std;
int ls(int arr[],int x,int i,int n)
{
    if(i==n)
    {
        return 0;
    }
    if (arr[i]==x)
    {
        return i;
    }
    return ls(arr,x,i+1,n);
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
    cout<< ls(arr,x,0,n);
    
}