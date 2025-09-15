#include <iostream>
using namespace std;
int main ()
{
    int i,j,row=4,column=4,start,end;
    int arr[100][100];
    cout<<"enter the contents of the matrix:";
    for (i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cin>>arr[i][j];
        }

    }
    cout<<endl;

    for (i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<endl;
    //code for transpose of the matrix
    for (i=0;i<row;i++)
    {
        for(j=i+1;j<column;j++)
        {
            swap(arr[i][j],arr[j][i]);
        }
    }
    //code for reversing th elements of each row
    for(i=0;i<row;i++)
    {
        start=0;
        end=column-1;
        while(start<end)
        {
            swap(arr[i][start],arr[i][end]);
            start++;
            end--;
        }


    }
    cout<<endl;
    //code to print the final matrix 
    for (i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }



}