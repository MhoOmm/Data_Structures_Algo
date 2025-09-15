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
int height(node * root,int &valid)
{
    if (root==NULL)
    {
        return 0;
    }
    int l=height(root->left,valid);
    int r=height(root->right,valid);
    if (abs(l-r)>1)
    {
        valid=0;
    }
    return (1+max(l,r));
}
bool is_balanced(node*root)
{
    int valid =1;
    height(root,valid);
    return valid;

}

int main()
{
    node* root;
    cout<<"enter the value of the root:";
    root=binarytree();
    int ans=is_balanced(root);
    if (ans==1){
        cout<<"tree is balanced:)";
    }
    else{
        cout<<"tree is not balanced:(";
    }
}