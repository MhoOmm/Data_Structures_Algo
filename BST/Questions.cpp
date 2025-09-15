#include <iostream>
using namespace std;
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
//FUNCTION TO FIND THE MININUM DIFFRENCE OF TWO ELEMENITS IN BST 
//TC-O(N),SC-O(n)
int prev=INT8_MIN;
int ans=INT8_MAX;


void mindis(node* root,int &prev,int &ans )
{
    if(root==NULL)
    {
        return;
    }
    mindis(root->left,prev,ans);
    if(prev!=INT8_MIN)//AS ROOT->DATA-PREV IN THE LEaf node will be 
    //bigger than the value of int_min
    {
        ans=min(ans,root->data-prev);
    }
    prev=root->data;
    mindis(root->right,prev,ans);

}

//FUNTCION TO FIND THE SUM OF K SMALLEST ELEMENT IN BST 

void sum ( node* root ,int&k,int&ans)
{
    if (root==NULL)
    {
        return ;
    }
    if(k==0)
    {
        return ;
    }
    sum(root->left,k,ans);
    ans+=root->data;
    k--;
    sum(root->right,k,ans);

}
//Function to find the kth largest element in bst 

int ans=INT8_MIN;
void kg(node*root,int&k,int&ans)
{
    if (!root)
    {
        return;
    }
    kg(root->right,k,ans);
    k--;
    if (k==0)
    {
        ans=root->data;
    }
    if(k<=0)
    {
        return;
    }
    kg(root->left,k,ans);
}
int start;
int end;
int mid;
node*bstarr(vector<int>&arr,int start,int end,vector <int>&ans)
{
    int mid=start+(end-start)/2;
    ans.push_back(arr[mid]);
    bstarr(arr,start,mid-1,ans);
    bstarr(arr,mid+1,end,ans);
}
//MAKE A BINARY SEARCH TREE THROUGH SORTED ARRAY

node*  createbst(vector<int>&arr,int start,int end)
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


