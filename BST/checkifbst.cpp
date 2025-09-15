#include <iostream>
#include <vector>
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
void inorder ( node* root,vector <int>&ans)
{
    
    if( root==NULL){
        return;
    }
    inorder( root->left,ans);
    ans.push_back(root->data);
    inorder( root->right,ans);
}
bool checkbst(node*root,vector<int>ans)
{
    inorder(root,ans);
    for (int i=1;i<=ans.size();i++)
    {
        if(ans[i]<=ans[i-1]);
        return 1;
    }
    
    
}


int main ()
{
    node * root=NULL;
    int arr[]={10,8,7,4,6,3,2};
    for( int i=0;i<7;i++)
    {
        root=insert(root,arr[i]);
    }
    vector <int>ans{0};
    cout<<endl;
    int check=checkbst(root,ans);
    if(check==1)
    {
        cout<<"is a bst";
    }
    else {
        cout<<"not a bst";
    }



}