#include <iostream>
using namespace std;

// converting maxheap to sorted array
void heapify(int arr[],int index ,int n)
{
    int largest=index;
    int left=index*2+1;
    int right=index*2+2;

    if (left<n && arr[index]<arr[left])
    {
        largest=left;
    }
    if (right<n && arr[index]<arr[right])
    {
        largest=right;
    }
    if (largest!=index)
    {
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}
void buildMH(int arr[],int n)
{
    for(int i=(n-1)/2;i>=0;i--)
    {
        heapify(arr,i,n);
    }

}

void sortarray(int arr[],int n)
{
    for(int i =n-1;i>0;i--)
    {
        swap(arr[i],arr[0]);
        heapify(arr,0,i);
    }

}
 void print(int arr[],int n)
 {
    for(int i =0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
 }

int main()
{
    int arr[]={14,15,20,31,30,16,17,18,19,2};
    buildMH(arr,10);
    sortarray(arr,10);
    print(arr,10);
    return 0;

}