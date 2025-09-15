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
void size(node* root,int &co)//NLR TRAVERSAL
{
    if(root==NULL)
    {
        return;
    }
    co++;
    size(root->left,co);
    size(root->right,co);
}
//ALT FUNCTION 
// int size(node * root)
// {
//     if ( root=NULL)
//     {
//         return 0;
//     }
//     return (1+size(root->left)+size(root->right));
// }
int main ()
{
    node* root;
    cout<<"enter the value of the root:";
    root=binarytree();
    int co=0;
    size(root,co);
    cout<<"size of binary tree is:"<<co;
}
