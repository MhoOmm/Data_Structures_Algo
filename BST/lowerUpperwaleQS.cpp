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
//FUNCTION TO CREATE BST FROM PREORDER RETURN 1,
//IF POSSIBLE AND 0 IF NOT .
void bst (int arr[],int& index,int lower,int upper,int n)
{
    if(index==n||arr[index]<lower||arr[index]>upper)
    {
        return;
    }
    int value=arr[index];//value dalo
    bst(arr,index,lower,value,n);//left
    bst(arr,index,value,upper,n);//right


}
bool can_represent(int arr[],int n)
{
    int index=0;
    bst(arr,index,0,1000,n);
    return index==n;
}
//ismein segmentation fault aa rha hai kyunki at n=100000
//kyunki left skewed tree hai to stack mein o(n) mein store
// nhi kar payega itne sare operations.


//LEAST COMMON ANCESTOR (IMP)
node* lca(node*root,int n1,int n2)
{
    if(!root)
    {
        return NULL;
    }
    if(root->data>n1&&root->data>n2)
    {
        return lca(root->left,n1,n2);
    }
    else if(root->data<n1&&root->data<n2)
    {
        return lca(root->right,n1,n2);
    }
    else{
        return root;
    }
}

//PRINT THE ELEMENTS OF A BST WITHIN A GIVEN RANGE N1 & N2
//RETURN A SORTED ARRAY
void printa(node* root,int n1,int n2,vector<int>arr)
{
    if(root==NULL)
    {
        return;
    }
    if(root->data>n1 && root->data>n2)
    {
        printa(root->left,n1,n2,arr);
    }
    else if(root->data<n1 && root->data<n2)
    {
        printa(root->right,n1,n2,arr);
    }
    else{
        printa(root->left,n1,n2,arr);
        arr.push_back(root->data);
        printa(root->right,n1,n2,arr);
    }
}

