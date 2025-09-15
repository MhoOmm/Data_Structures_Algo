#include <iostream>
using namespace std;
int main ()
{
    int n,i,j,start,end,mid,ele;
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
        cout<<arr[i]<<" ";
    }
    cout<<"enter the element to search";
    cin>>ele;
    start=0;
    end=n-1;
    while(start<=end)
    {
        mid=start+(end-start)/2;
        if(arr[mid]==ele)
        {
            cout<<"found at:"<<start;
            break;
        }
        else if(arr[mid]<ele)
        {
            start=mid+1;
        }
        else if(arr[mid]>ele)
        {
            end=mid-1;
        }
    }
}