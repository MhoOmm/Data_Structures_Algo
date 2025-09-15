#include <iostream>
using namespace std;
void printN(int n)
{
    if(n==1)
    {
        cout<<"1"<<endl;
        return;
    }
    cout<<n<<endl;
    printN(n-1);
}
int main()
{
    int n;
    cout<<"enter number:";
    cin>>n;
    printN(n);

}