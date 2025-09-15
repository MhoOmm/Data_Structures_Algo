#include <iostream>
using namespace std;
class node{
    public:
    int data,height;
    node * left ,* right;
    node( int value)
    {
        data=value;
        height=1;
        left=NULL;
        right=NULL;
    }
};


int getheight(node* root)
{
    if(root==NULL)
    {
        return 0;
    }
    return root->height;
}


int getbalance(node* root)
{
    return (getheight(root->left)-getheight(root->right));
}

node* leftrotation ( node* root)
{
    node* child=root->right;
    node* childl=child->left;
    child->left=root;
    root->right=childl;
    //updating height
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));

    return child;

}
node* rightrotation( node* root)
{
    node* child=root->left;
    node* childl=child->right;
    child->right=root;
    root->left=childl;
    //updating height
    root->height=1+max(getheight(root->left),getheight(root->right));
    child->height=1+max(getheight(child->left),getheight(child->right));

    return child;

}

node* insert(node* root,int key)
{
    //Doesn't exist
    if(!root)
    {
        return new node(key);
    }
    //exist
    if( root->data < key)
    {
        root->right=insert(root->right,key);
    }
    else if(root->data > key)
    {
        root->left=insert(root->left ,key);
    }
    else//for duplicate elements 
    {
        return root;
    }
    //UPDATING HEIGHT OF THE ROOT
    root->height=1+max(getheight(root->left),getheight(root->right));

    //BALANCING CHECK
    int balance=getbalance(root);

    //LEFT BALANCE CASE LL
    if(root->left->data > key && balance > 1)
    { 
        return rightrotation(root);
    }
    //RIGHT BALANCE CASE RR
    else if(root->right->data < key && balance < (-1) )
    {
        return leftrotation(root);

    }
    //LEFT RIGHT BALANCE CASE LR
    else if( key>root->left->data && balance > 1)
    {
        root->left =leftrotation(root->left);
        return rightrotation(root);

    }
    //RIGHT LEFT BALANCE CASE RL
    else if( key<root->right->data && balance < -1)
    {
        root->right=rightrotation(root->right);
        return leftrotation(root);

    }
    //NO UNBALANCING
    else {
        return root;
    }
}

void inorder(node* root)
{
    if (!root)
    {
        return;
    }
    inorder(root->left);
    cout<<root->data;
    inorder( root->right);
}

int main()
{
    //DUPLICATE ELEMENTS ARE NOT ALLOWED
    node* root=NULL;
    root =insert(root,10);
    root =insert(root,70);
    root =insert(root,30);
    root =insert(root,25);
    root =insert(root,37);
    root =insert(root,18);
    root =insert(root,20);

    cout<<"inorder traversal";
    inorder(root);


}