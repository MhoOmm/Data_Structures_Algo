#include <iostream>
using namespace std;
int main ()
{
    int ele,n,i;
    int arr[100];
    cout<<"enter the number of elements in the array:";
    cin>>n;
    arr[0]=0;
    arr[1]=1;
    for (i=2;i<n;i++)
    {
        arr[i]=arr[i-1]+arr[i-2];
    }
    cout<<"the array is:\n";
    for ( i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<"enter the position\n";
    cin>>ele;
    cout<<"element at position "<<ele<<" is:"<<arr[ele-1];
}