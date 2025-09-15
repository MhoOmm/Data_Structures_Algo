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
node* insertmid(node* &head,int pos,int val)
{
    node* temp=head;
    for(int i=0;i<pos-1;i++){
        temp=temp->next;
    }
    node* nn=new node(val);
    nn->next =temp->next ;
    temp->next =nn;
    return head;
}

int main ()
{
    int arr[]={1,2,3,4,5};

    node * head=NULL;
    //recursively add nodes to the ll from the array 
    head=createll(arr,5,0);
    //to print the linked list 
    node* temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }
    cout<<endl;
    //function call to add a node in the pos
    int pos,value;
    cout<<"enter position to enter:";
    cin>>pos;
    cout<<"enter the value to enter:";
    cin>>value;
    insertmid(head,pos,value);
    //to print the linked list 
    temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}