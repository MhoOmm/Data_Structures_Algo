#include <iostream>
using namespace std;
void printN(int n)
{
    if(n==0)
    {
        cout<<"0"<<endl;
        return;
    }
    if(n%2==0)
    {
        cout<<n<<endl;
    }
    printN(n-1);
}
int main()
{
    int n;
    cout<<"enter number:";
    cin>>n;
    printN(n);

}