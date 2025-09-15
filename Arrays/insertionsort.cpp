#include <iostream>
using namespace std;
int main ()
{
    int n,i,j;
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
    // //code for insertion sort in increasing order 
    // for(i=1;i<n;i++)//starting from the second element 
    // {
    //     for(j=i;j>0;j--)//uss element se peeche zero take usko correct order mein le aayega
    //     {
    //         if(arr[j]<arr[j-1])
    //         {
    //             swap(arr[j],arr[j-1]);//warna swap to ho hi rha hai 
    //         }
    //         else{
    //             break;//agar uske ke pehle aur koi chota nhi hai to break
    //         }
    //     }
    // }

    //code for insertion sort in decreasing order

    // for(i=1;i<n;i++)//starting from the second element 
    // {
    //     for(j=i;j>0;j--)//uss element se peeche zero take usko correct order mein le aayega
    //     {
    //         if(arr[j]>arr[j-1])
    //         {
    //             swap(arr[j],arr[j-1]);//warna swap to ho hi rha hai 
    //         }
    //         else{
    //             break;//agar uske ke pehle aur koi chota nhi hai to break
    //         }
    //     }
    // }

    //code for insertion sort in increasing order from back
    for(i=n-2;i>=0;i--)//starting from the second element 
    {
        for(j=i;j<n;j++)//uss element se peeche zero take usko correct order mein le aayega
        {
            if(arr[j]>arr[j+1])
            {
                swap(arr[j],arr[j+1]);//warna swap to ho hi rha hai 
            }
            else{
                break;//agar uske ke pehle aur koi chota nhi hai to break
            }
        }
    }


    cout<<"\nthe sorted array is:\n";
    for ( i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
}