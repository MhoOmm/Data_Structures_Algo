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
int main ()
{
    node* head=NULL;
    int n;
    cout<<"enter the value of the node";
    cin>>n;
    head=new node (n);
    node *temp1=new node(50);
    head->next=temp1;
    node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<endl;
        cout<<"node address:"<<temp<<endl;
        cout<<"next node address:"<<temp->next<<endl;
        temp=temp->next;
    }
    

}