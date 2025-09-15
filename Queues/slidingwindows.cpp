#include <iostream>
#include <vector>
#include <queue>
using namespace std;
void display(queue<int>q)//NOTE
//pass by value horha aur pass by refrence nhi taki main array
//pe koi ched khani na ho :)
{
    while(!q.empty())
    {
        cout<<q.front();
        q.pop();
    }
    cout<<endl;
}

// function le rha to find the first negative integer in the array
// using queues
//O(nk)
int displayneg(queue<int>q)
{
    while(!q.empty())
    {
        if(q.front()<0)
        {
            return q.front();
        }
        q.pop();
    }
    return 0;
}
// after this store the neg elements in a vector 
//and dislplay the vector

// ALt approach more optimized for O(N)

void slidewindow(vector<int>arr,int k ,int n)
{
    queue<int>q;
    for(int i=0;i<k-1;i++)
    {
        q.push(arr[i]);
    }
    for(int i=k-1;i<n;i++)
    {
        q.push(arr[i]);
        display(q);
        q.pop();
    }

}
int main ()
{

}