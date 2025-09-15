#include <iostream>
using namespace std;
int main ()
{
    int ele,n,i,temp;
    int arr[100];
    cout<<"enter the number of elements in the array:";
    cin>>n;
    cout<<"enter the elements of the array :\n";
    for (i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"the array is:\n";
    for ( i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
    temp=arr[n-1];
    for (i=n-2;i>=0;i--)
    {
        arr[i+1]=arr[i];
    }
    arr[0]=temp;
    cout<<"updated array:\n";
    for ( i=0;i<n;i++)
    {
        cout<<arr[i]<<endl;
    }
}