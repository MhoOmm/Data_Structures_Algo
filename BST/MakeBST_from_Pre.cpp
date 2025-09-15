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
node* bst (vector<int>&post,int index, int &lower,int & upper)
{
    if(index==post.size()||post[index]<lower||post[index]>upper)
    {
        return;
    }
    node* root=new node(post[index++]);
    root->left=bst(post,index,lower,root->data);
    root->right=bst(post,index,root->data,upper);
    return root;
}
int main()
{
    int index=0;
    int lower=INT8_MIN;
    int upper=INT8_MAX;
    vector<int> post={};
    node* root=bst(post,index,lower,upper);


}