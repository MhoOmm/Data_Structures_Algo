#include <iostream>

using namespace std;
int main ()
{
    int ele,n,i;
    int arr[100];
    cout<<"enter the number of elemenst in the array:";
    cin>>n;
    cout<<"enter the elements of the array :\n";
    for (i=0;i<n-1;i++)
    {
        cin>>arr[i];
    }
    cout<<"the array is:\n";
    for ( i=0;i<n-1;i++)
    {
        cout<<arr[i]<<endl;
    }
    //sum of all numbers upto n
    int sumn=0;
    for(i=1;i<=n;i++)
    {
        sumn+=i;
    }
    //sum of elments in the array
    int suma=0;
    for(i=0;i<n-1;i++)
    {
        suma+=arr[i];
    }
    cout<<"missing number:"<<(sumn-suma);

}