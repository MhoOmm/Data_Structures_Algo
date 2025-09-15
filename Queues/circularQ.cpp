#include <iostream>
#include <vector>
using namespace std;
class queue
{
    
    int *arr ;
    int front;
    int rear;
    int size;
    public:
    queue(int n)
    {
        arr=new int[n];
        front=-1;
        rear=-1;
        size=0;
    }
    bool isempty()
    {
        return front == -1;
    }
    bool isfull()
    {
        return (rear+1)%size==front;
    }

    void push(int n)
    {
        if(isempty())
        {
            rear=front=0;
            arr[0]=n;
        }
        else if(rear==size-1)
        {
            cout<<"queue is full";
            return;
        }
        else{
            rear=(rear+1)%size;
            arr[rear]=n;
        }
    }
    int pop()
    {
        if(rear==-1 && front ==-1)
        {
            cout<<"queue underflow";
        }
        else if ( front > rear)
        {
            cout<<"queue is empty";
            front=rear=0;
        }
        else {
            int a=arr[front];
            front=(front+1)% size;
            return a;
        }

    }
    int start()
    {
        if (isempty())
        { 
            cout<<"stack is empty";
            return -1;
        }
        else 
        {
            return arr[front];
        }
    }
};

int main( )
{
    queue q(6);
    q.push(1);
    q.push(2);
    q.push(3);
    int a=q.pop();
    cout<<a;
}