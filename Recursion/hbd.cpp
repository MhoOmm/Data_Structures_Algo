#include <iostream>
using namespace std;
void funhbd(int n)
{
    if (n==0)//BASE CASE I.e.terminating condition
    {
        cout<<"hbd"<<endl;
        return;
    }
    cout<<n<<"days left for birthday"<<endl;
    funhbd(n-1);//calling the same function inside the function

}
int main ()
{
    int n;
    cout<<"enter no of days";
    cin>>n;
    funhbd(n);
    return 0;

}