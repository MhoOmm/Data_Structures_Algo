/* The functions which
builds the segment tree */
vector<int>segTree;
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
    segTree[idx] = min(segTree[(2*idx)+1],segTree[(2*idx)+2]);
}
int *constructST(int arr[], int n) {
    // Your code here
    segTree.resize(4*n);
    buildTree(0,0,n-1,arr);
    return segTree.data();
}

/* The functions returns the
 min element in the range
 from a and b */
 
int queryMin(int st[], int a, int b, int idx, int l, int r)
{
    // No overlap
    if(l > b || r < a)
    {
        return INT_MAX;
    }

    // Complete overlap
    if(a <= l && r <= b)
    {
        return st[idx];
    }

    // Partial overlap
    int mid = (l + r) / 2;

    int leftChildAns = queryMin(
        st, a, b, 2 * idx + 1, l, mid
    );

    int rightChildAns = queryMin(
        st, a, b, 2 * idx + 2, mid + 1, r
    );

    return min(leftChildAns, rightChildAns);
}

int RMQ(int st[], int n, int a, int b) {
    // Your code here
    return queryMin(st, a, b, 0, 0, n - 1);
}