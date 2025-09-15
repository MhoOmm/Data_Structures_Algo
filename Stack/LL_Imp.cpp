#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node* next ;
    node (int val){
        data=val;
        next=NULL;
    }
};
class stack{
    node* top;
    int size;
    public:
    stack()
    {
        top=NULL;
        size=0;
    }
    void push(int value)
    {
        node* temp=new node(value);
        if(temp==NULL)
        {
            cout<<"stack overflow";
            return;
        }
        temp->next=top;
        top=temp;
        size++;
    }
    void pop()
    {
        if ( top=NULL)
        {
            cout<<"stack undeflow";
            return ;
        }
        node* del=top;
        top=top->next;
        delete del;
        size--;
    }
    int peek()
    {
        if ( top==NULL)
        {
            cout<<"stack empty";
            return -1;
        }
        else {
            return top->data;
        }
    }
    bool isempty()
    {
        if (top==NULL)
        {
            return 1;
        }
        else{
            return 0;
        }
    }
    int isize()
    {
        return size;
    }

};
int main ()
{

}