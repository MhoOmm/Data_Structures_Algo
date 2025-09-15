#include <iostream>
using namespace std;
class node {
    public:
    int data;
    node* left ;
    node* right;
    node(int value)
    {
        data=value;
        left=NULL;
        right=NULL;

    }
};
node* insert(node* root,int value)
{
    if(root==NULL)
    {
        node * temp=new node(value);
        return temp ;
    }
    if(value>root->data)
    {
        root->right=insert(root->right,value);
    }
    else
    {
        root->left=insert(root->left,value);
    }
    return root;

}
bool search(node* root,int target)
{
    if (root==NULL)
    {
        return 0;
    }
    if ( root->data==target)
    {
        return 1;
    }
    if (target<root->data)
    {
        search(root->left,target);
    }
    else{
        search(root->right,target);
    }
    
}
void inorder ( node* root)
{
    if( root==NULL){
        return;
    }
    inorder( root->left);
    cout<<root->data;
    inorder( root->right);
}

int main ()
{
    node * root=NULL;
    int arr[]={10,8,7,4,6,3,2};
    for( int i=0;i<7;i++)
    {
        root=insert(root,arr[i]);
    }
    inorder(root);
    int ans=search( root,10);
    cout<<endl;
    
    if(ans==1)
    {
        cout<<"element found";
    }
    else{
        cout<<"not found";
    }



}