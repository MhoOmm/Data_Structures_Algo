#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main()
{
    queue<int>q;
    q.push(10);
    q.push(20);
    q.push(40);
    q.push(50);
    cout<<q.front();
    q.pop();
    cout <<q.size();

}
