#include <iostream>
using namespace std;
void printN(int n)
{
    if(n==1)
    {
        cout<<"1"<<endl;
        return;
    }
    printN(n-1);
    cout<<n<<endl;
}
// function to print the even numbers form 0 to n 
void evenp(int n)
{
    if (n==0)
    {
        cout<<0<<endl;
        return;
    }
    evenp(n-2);
    cout<<n<<endl;

}
int main()
{
    int n;
    cout<<"enter number:";
    cin>>n;
    if(n%2==1)
    {
        n--;
    }
    evenp(n);

}