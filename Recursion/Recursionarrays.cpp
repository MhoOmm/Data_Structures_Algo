#include <iostream>
using namespace std;
void print(int arr[],int n)
{
    if(n==0)
    {
        cout<<arr[0]<<" ";
        return;
    }
    print(arr,n-1);
    cout<<arr[n]<<" ";
}
int sums(int arr[],int n)
{
    if(n==0)
    {
        return arr[0];
    }
    return (arr[n]+sums(arr,n-1));
}
int minimum(int arr[],int n)
{
    if(n==0)
    {
        return arr[0];
    }
    return min(arr[n],minimum(arr,n-1));

}
int main ()
{
    int arr[100];
    int n ,i;
    cout<<"enter n:";
    cin>>n;
    cout<<"enter the elemenst of the array:"<<endl;
    for(i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    print(arr,n-1);
    cout<<endl;
    // int sum =sums(arr,n-1);
    // cout<<"the sum of all elements:"<<sum;
    cout<<"smalllest element in the array:"<<minimum(arr,n-1);
}