#include <iostream>
#include <queue>
using namespace std;
class node{
    public:
    int data;
    node * left ;
    node * right;
    node( int x)
    {
        data=x;
        left=NULL;
        right=NULL;
    }
};
int main()
{
    int x1,x2,r;
    cout<<"enter the value of root node:";
    cin>>r;
    queue<node*>q;
    node* root=new node(r);
    q.push(root);
    while(!q.empty())
    {
        node*temp=q.front();
        q.pop();
        cout<<"enter the value of left child of"<<temp->data<<":";
        cin>>x1;//VALUE OF THE LEFT CHILD 
        if ( x1!=-1)
        {
            temp->left =new node(x1);//CREATION OF LEFT CHILD
            q.push(temp->left);
        }


        cout<<"enter the value of right child of"<<temp->data<<":";
        cin>>x2;//VALUE OF THE RIGHT CHILD 
        if ( x2!=-1)
        {
            temp->right=new node(x2);//CREATION OF THE RIGHT CHILD
            q.push(temp->right);
        }

    }


}