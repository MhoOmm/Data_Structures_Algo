//SEARCH ELEMENT IN ARRAY
#include <iostream>
#include <limits.h>
using namespace std;
int main ()
{
    int ele,n,i;
    int arr[100];
    cout<<"enter the number of elemenst in the array:";
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
    // cout<<"enter element to search:";
    // cin>>ele;
    // int index;
    // for (int i=0;i<n;i++)
    // {
    //     if(arr[i]==ele)
    //     {
    //         index = i ;
    //         break;
    //     }
    //     else
    //     {
    //         index = -1;
    //     }
    // }
    // cout<<"the index is :"<<index;

    //reversing an array 
    // int m=0;
    // int j=n;
    // while(m<j)
    // {
    //     swap(arr[m],arr[j]);
    //     m++;
    //     j--;
    // }
    // cout<<"the array after reversing is:\n";
    // for (int i=0;i<n;i++)
    // {
    //     cout<<arr[i]<<endl;
    // }


    //second max element of the array 
    // int ans =INT_MIN;
    // //for max number
    // for(i=0;i<n;i++)
    // {
    //     if (arr[i]>ans)
    //     {
    //         ans=arr[i];
    //     }
    // }
    // //for second max
    // int sec=INT_MIN;
    // for(i=0;i<n;i++)
    // {
    //     if (arr[i]!=ans)
    //     {
    //         sec=max(arr[i],sec);
    //     }
    // }
    // cout<<"second maximum number is:"<<sec;
}

