#include<iostream>
using namespace std;
#include<vector>
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

// make a binary heap from two heap
void heapify(vector<int> arr,int index ,int n)
{
    int largest=index;
    int left=index*2+1;
    int right=index*2+2;

    if (left<n && arr[index]<arr[left])
    {
        largest=left;
    }
    if (right<n && arr[index]<arr[right])
    {
        largest=right;
    }
    if (largest!=index)
    {
        swap(arr[largest],arr[index]);
        heapify(arr,largest,n);
    }
}

vector<int> merge(vector<int>&a,vector<int>&b,int n, int m)
{
    vector<int>ans;
    for(int i=0;i<n;i++)
    {
        ans.push_back(a[i]);
    }
    for(int i=0;i<m;i++)
    {
        ans.push_back(b[i]);
    }

    int size=ans.size();
    for ( int i= size/2-1;i>=0;i--)
    {
        heapify(ans,i,n);
    }
    return ans;
}

// is binary tree a heap

int count(node* tree)
{
    if(tree=NULL)
    {
        return 0;
    }

    return 1+count(tree->left)+count(tree->right);
    
}
bool cbt(node* root, int index, int nodes)
{
    if (!root)// child nhi hai 
    {
        return 1;
    }
    if (index>=nodes)
    {
        return 0;
    }

    //left & right side check
    return cbt( root->left, index*2 +1, nodes) && cbt( root->right, index*2 +2, nodes);
}

bool maxheap(node* root)
{
    // root is null
    //only left child exist  
    //only right child exist 
    //both exist

    if( root->left)
    {
        if (root->data < root->left->data)
        {
            return 0;
        }
       if (! maxheap( root->left)){
        return 0;
       }
    }
    if( root->right)
    {
        if (root->data < root->right->data)
        {
            return 0;
        }
        return maxheap( root->right);
    }




}

bool is_heap(node* tree)
{
    //to count the number of nodes
    int num=count(tree);

    //to check if the tree is a cbt
    bool ans=cbt(tree,0,num);

    if (ans==0)
    {
        return 0;
    }

    // to check if parent is bigger than child
    return maxheap(tree);


}


int main()
{
    
    return 0;
}