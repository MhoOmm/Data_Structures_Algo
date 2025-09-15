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
void leftview(node * root,int level,vector<int>&ans)
{
    if (root==NULL)
    {
        return;
    }
    if (level==ans.size())
    {
        ans.push_back(root->data);
    }
    leftview(root->left,level+1,ans);
    leftview(root->right,level+1,ans);
}
int main()
{
    node* root;
    cout<<"enter the value of the root:";
    root=binarytree();

    vector<int>ans;
    int level=0;
    leftview(root,level,ans);
    for(int i=0;i<ans.size();i++)
    {
        cout<<ans[i]<<" "<<endl;
    }
}