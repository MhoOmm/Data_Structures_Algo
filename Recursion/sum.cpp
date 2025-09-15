#include <iostream>
using namespace std;
int sum(int num)
{
    if (num==1)
    {
        return 1;
    }
    return (num+sum(num-1));
}
int sums(int num)
{
    if (num==1)
    {
        return 1;
    }
    return ((num*num)+sum(num-1));
}
int main ()
{
    int n ;
    cout<<"enter the numebr";
    cin>>n;
    cout<<sums(n);
}