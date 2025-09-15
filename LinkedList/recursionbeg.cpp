#include <iostream>
using namespace std;
class node{
    public:
    int data;
    node * next;
    node(int value)
    {
        data=value;
        next=NULL;
    }
};
node* createll(int arr[],int size,int i,node*prev)
{
    if (i==size)
    {
        return prev;
    }
    node* nn=new node(arr[i]);
    nn->next=prev;
    return createll(arr,size,i+1,nn);
}
int main ()
{
    int arr[]={1,2,3,4,5};

    node * head=NULL;
    head=createll(arr,5,0,head);
    node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}