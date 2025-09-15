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
node* binarytree()
{
    int val;
    cin>>val;
    if(val==-1)
    {
        return NULL;
    }
    node * temp=new node(val);
    //FOR LEFT SIDE ACCESS
    cout<<"enter the left child value of:"<<val<<":";
    temp->left=binarytree();
    //FOR RIGHT SIDE ACCESS
    cout<<"enter the right child value of:"<<val<<":";
    temp->right=binarytree();
    //AT THE END WE RETURN THE ADDRESS OF THE CURRENT NODE
    return temp;
}
void pre_order(node* root)//NLR TRAVERSAL
{
    if(root==NULL)
    {
        return;
    }
    cout<<root->data<<" ";
    pre_order(root->left);
    pre_order(root->right);
}
void in_order(node* root)
{
    if(root==NULL)
    {
        return;
    }
    in_order(root->left);
    cout<<root->data<<" ";
    in_order(root->right);

}
void post_order(node* root)
{
    if(root==NULL)
    {
        return;
    }
    post_order(root->left);
    post_order(root->right);
    cout<<root->data<<" ";

}
int main()
{
    cout<<"enter the root node:";
    node* root;
    root=binarytree();
    cout<<endl;
    pre_order(root);
    cout<<endl;
    in_order(root);
    cout<<endl;
    post_order(root);


}