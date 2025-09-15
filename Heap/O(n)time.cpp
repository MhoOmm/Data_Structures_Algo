#include <iostream>
using namespace std;

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
int main()
{
    int arr[]={14,15,19,20,31,30,15,17,18,19};
    buildMH(arr,10);

}