class NumArray {
public:
    vector<int>segTree;
    int n;
    void buildTree(int idx,int l,int r,vector<int>& nums)
    {
        if(l==r)
        {
            segTree[idx] = nums[l];
            return;
        }
        int mid = (l+r)/2;
        // left subtree
        buildTree((2*idx)+1,l,mid,nums);
        // right subtree
        buildTree((2*idx)+2,mid+1,r,nums);
        segTree[idx] = segTree[(2*idx)+1]+segTree[(2*idx)+2];
    }
    int rangeSum(int left,int right,int idx,int l,int r){
        // out of bound case
        if(l>right || r<left )
        {
            return 0;
        }
        // in bound case
        if(left<=l && r<=right)
        {
            return segTree[idx];
        }
        // in bound but some elements leaking
        int mid = (l+r)/2;
        int leftChildAns = rangeSum(left,right,2*idx+1,l,mid);
        int rightChildAns = rangeSum(left,right,2*idx+2,mid+1,r);
        return leftChildAns + rightChildAns;
    }
    NumArray(vector<int>& nums) {
        n = nums.size();
        segTree.resize(4*n);
        buildTree(0,0,n-1,nums);
    }
    
    int sumRange(int left, int right) {
        return rangeSum(left,right,0,0,n-1);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * int param_1 = obj->sumRange(left,right);
 */