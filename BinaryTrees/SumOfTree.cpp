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
void sumTree(node* root,int &sum)//NLR TRAVERSAL
{
    if(root==NULL)
    {
        return;
    }
    sum+=root->data;
    sumTree(root->left,sum);
    sumTree(root->right,sum);
}

int main ()
{
    node* root;
    cout<<"enter the value of the root:";
    root=binarytree();
    int sum=0;
    sumTree(root,sum);
    cout<<"sum of binary tree is:"<<sum;
}
