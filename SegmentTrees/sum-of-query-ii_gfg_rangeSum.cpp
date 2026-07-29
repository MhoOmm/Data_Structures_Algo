class Solution {
  public:
    vector<int>segTree;
    int rangeSum(int start,int end,int idx,int l,int r)
    {
        // out of bound case
        if(l>end || r<start )
        {
            return 0;
        }
        // in bound case
        if(start<=l && r<=end)
        {
            return segTree[idx];
        }
        // in bound but some elements leaking
        int mid = (l+r)/2;
        int leftChildAns = rangeSum(start,end,2*idx+1,l,mid);
        int rightChildAns = rangeSum(start,end,2*idx+2,mid+1,r);
        return leftChildAns + rightChildAns;
    }
    void buildTree(int idx,int l,int r,int arr[])
    {
        if(l==r)
        {
            segTree[idx] = arr[r];
            return;
        }
        int mid = (l+r)/2;
        buildTree((2*idx)+1,l,mid,arr);
        buildTree((2*idx)+2,mid+1,r,arr);
        segTree[idx] = segTree[(2*idx)+1]+segTree[(2*idx)+2];
    }
    vector<int> querySum(int n, int arr[], int q, int queries[]) {
        // code here
        segTree.resize(4*n);
        buildTree(0,0,n-1,arr);
        vector<int>ans;
        for(int i=0;i<2*q;i+=2)
        {
            int start = queries[i]-1;
            int end = queries[i+1]-1;
            ans.push_back(rangeSum(start,end,0,0,n-1));
        }
        return ans;
    }
};