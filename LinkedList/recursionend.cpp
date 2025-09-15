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
node* createll(int arr[],int size,int i)
{
    if (i==size)
    {
        return NULL;
    }
    node* nn=new node(arr[i]);
    nn->next=createll(arr,size,i+1);
    return nn;
}
int main ()
{
    int arr[]={1,2,3,4,5};

    node * head=NULL;
    head=createll(arr,5,0);
    node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}