//CODE TO SORT THE ARRAY PF 0'S AND 1'S IN ORDER 000111
#include <iostream>
using namespace std;
int main ()
{
    int n,i,j,start,end;
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
    cout<<endl;
    start=0;
    end=n-1;
    while(start<=end)
    {
        if(arr[start]==0)
        {
            start++;
        }
        else{
            if(arr[end]==0)
            {
                swap(arr[start],arr[end]);
                start++;
                end--;
            }
            else{
                end--;
            }
        }

    }
    cout<<"the sorted array\n";
    for(i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}

