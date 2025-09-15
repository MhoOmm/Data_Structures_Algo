#include <iostream>
using namespace std;
#include <vector>
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
node* bst (vector<int>&pre,int index, int &lower,int & upper)
{
    if(index==pre.size()||pre[index]<lower||pre[index]>upper)
    {
        return;
    }
    node* root=new node(pre[index++]);
    root->right=bst(pre,index,root->data,upper);
    root->left=bst(pre,index,lower,root->data);
    return root;
}
int main()
{
    int index=0;
    int lower=INT8_MIN;
    int upper=INT8_MAX;
    vector<int> pre={};
    node* root=bst(pre,index,lower,upper);


}