#include <iostream>
#include <vector>
using namespace std;
class lnode{
    public:
    int key;
    lnode* next;
};
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
void inorder(node* root,vector<int>&ans)
{
    if(!root)
    {
        return;
    }
    inorder(root->left,ans);
    ans.push_back(root->data);
    inorder(root->right,ans);
}
vector<int>mergetwoBST(node*root1,node* root2)
{
    vector<int>ans1;
    vector<int>ans2;
}