#include <iostream>
using namespace std;
int main()
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
    for(i=0;i<row;i++)
    {
        start=0;
        end=column-1;
        while(start<end)
        {
            swap(arr[i][start],arr[i][end]);
            start++;;
            end--;
        }

    }
    for (i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }
    cout<<endl;
    int top,bottom;
    for(j=0;j<row;j++)
    {
        top=0;
        bottom=row-1;
        while(top<bottom)
        {
            swap(arr[top][j],arr[bottom][j]);
            top++;;
            bottom--;
        }

    }
    
    for (i=0;i<row;i++)
    {
        for(j=0;j<column;j++)
        {
            cout<<arr[i][j]<<" ";
        }
        cout<<endl;

    }
}
