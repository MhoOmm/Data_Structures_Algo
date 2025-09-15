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
void nl(node* root,int &conl)//NLR TRAVERSAL
{
    if (root==NULL)
    {
        return;
    }
    if(root->left!=NULL || root->right!=NULL)
    {
        conl++;
        return;
    }
    nl(root->left,conl);
    nl(root->right,conl);
}
int main()
{
    node* root;
    cout<<"enter the value of the root:";
    root=binarytree();
    int conl=0;
    nl(root,conl);
    cout<<"no of non-leaves in binary tree is:"<<conl;
}