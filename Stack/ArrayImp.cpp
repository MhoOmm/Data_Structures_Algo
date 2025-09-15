#include <iostream>
using namespace std;
class stack{
    int top,size;
    int* arr;
    public:
    stack(int s)
    {
        size =s;
        top=-1;
        arr=new int[s];
    }
    void push ( int value)
    {
        if (top==size-1)
        {
            cout<<"Stack Overflow"<<endl;
            return ;
        }
        else{
            top++;
            arr[top]=value;
        }
    }
    int pop()
    {
        if (top==-1)
        {
            cout<<"Stack Underflow"<<endl;
            return -1;
        }
        else{
            return arr[top--];
        }
    }
    int peek()
    {
        if ( top==-1)
        {
            cout<<"stack empty";
        }
        else{
            return arr[top];
        }

    }
    bool isempty()
    {
        if (top==-1)
        {
            return 1;
        }
        else{
            return 0;
        }

    }
    
    int  issize()
    {
        return top+1;
    }


};
int main()
{
    stack s(5);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    cout<<s.pop()<<endl;
    cout<<s.issize()<<endl;
    cout<<s.peek()<<endl;
    s.push(50);
    s.push(70);
    cout<<s.pop()<<endl;
    cout<<s.issize()<<endl;
    cout<<s.peek()<<endl;
    


}