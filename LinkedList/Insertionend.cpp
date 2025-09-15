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
void createll(node * &head,int value)
{
    node * newnode=new node(value);
    if (head==NULL)
    {
        head=newnode;
        return ;
    }
    else
    {
        node* temp=head;
        while (temp->next!=NULL)
        {
            temp=temp->next;
        }
        temp->next =newnode; 
    }
}
int main()
{
    int n,val=0;
    node* head=NULL;
    createll(head,1);
    createll(head,2);
    createll(head,3);
    node *temp=head ;
    while (temp!=NULL){
        cout<<temp->data<<"->";
    }

}