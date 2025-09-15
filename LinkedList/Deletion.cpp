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
node * delbeg(node* &head)
{
    node* temp =head;
    if (head==NULL){
        delete head;
    }
    head=head->next;
    delete temp;
    return head;
}
node * delmid(node* &head,int pos)
{
    node* temp =head;
    if (head==NULL){
        cout<<"no link list present";
    }
    else if(pos==1)
    {
        node* temp=head;
        head=head->next;
        delete temp;
    }
    for (int i=1;i<pos-1;i++){
        temp=temp->next;
    }
    node * del =temp->next;
    temp->next =temp->next ->next;
    delete del;
    return head;
}
node* delend(node * &head)
{
    
    if (head->next!=NULL)
    {
        delete head;
        head==NULL;
    }
    else{
        node *temp=head;
        while(temp->next != NULL){
            temp=temp->next;
        }
        node* del = temp->next;
        temp->next =NULL;
        delete del;
    }
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
    //function call to delete the node at the beginning
    // delbeg(head);

    //function call to delete a node in the pos
    // int pos;
    // cout<<"enter position to delete:";
    // cin>>pos;
    // delmid(head,pos);


    //function call to delete at the end
    delend(head);
    
    //to print the linked list 
    temp=head;
    while(temp){
        cout<<temp->data<<"->";
        temp=temp->next;
    }

}