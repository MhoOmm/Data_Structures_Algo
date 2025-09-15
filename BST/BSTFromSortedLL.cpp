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
node* createbst(vector<int>&arr,int start,int end)
{
    if(start>end)
    {
        return NULL;
    }
    int mid=start+(end-start)/2;
    node* root=new node(arr [mid]);
    root->left=createbst(arr,start,mid-1);
    root->right=createbst(arr,mid+1,end);
    return root;
}
node * sortvector(lnode* head)
{
    vector<int>ans;
    while(head)
    {
        ans.push_back(head->key);
        head=head->next;
    }
    return createbst(ans,0,ans.size());
    
}