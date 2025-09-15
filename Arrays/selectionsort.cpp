#include <iostream>
using namespace std;
int main ()
{
    int ele,n,i,j,index;
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
    // //code to sort the array using selection sort 
    // for(i=0;i<n-1;i++)
    // {
    //     index=i;//initially smallest element to swap smallest elewith later
    //     for(j=i+1;j<n;j++)
    //     {
    //         if (arr[j]<arr[index])
    //         {
    //             index=j;// got the smallest element
    //         }
    //     }
    //     swap(arr[i],arr[index]);
    // }

    // code for reverse of selection sort i.e, max elemet at last 
    for(i=n;i>0;i--)
    {
        index=i;//initially smallest element to swap smallest elewith later
        for(j=i-1;j>=0;j--)
        {
            if (arr[j]>arr[index])
            {
                index=j;// got the smallest element
            }
        }
        swap(arr[i],arr[index]);
    }

    cout<<"\nthe sorted array is:\n";
    for ( i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}