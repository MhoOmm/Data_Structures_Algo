#include <iostream>
#include <vector>
using namespace std;
void merge(int arr[],int start,int mid,int end)
{
    vector<int>temp((end-start)+1);
    int left=start;
    int right=mid+1;
    int index=0;
    while (left<=mid && right<=end)
    {
        if(arr[left]<=arr[right])
        {
            temp[index]=arr[left];
            index++;
            left++;
        }
        else{
            temp[index]=arr[right];
            index++;
            right++;
        }

    }
    while(left<=mid)
    {
        temp[index]=arr[left];
        index++;
        left++;
    }
    while(right<=end)
    {
        temp[index]=arr[right];
        index++;
        right++;
    }
    index=0;
    while (start<=end)
    {
        arr[start]=temp[index];
        start++;
        index++;
    }
}

void mergesort(int arr[],int start,int end)
{
    if (start==end)
    {
        return;
    }
    int mid=start+(end-start)/2;
    mergesort(arr,start,mid);
    mergesort(arr,mid+1,end);
    merge(arr,start,mid,end);
}

int main ()
{
    int arr[100];
    int n,x,i;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter the elements of the array:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    int start=0;
    int end=n-1;
    mergesort(arr,start,end);
    for (i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    
}