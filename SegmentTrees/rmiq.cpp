// Range Maximum Index Query 
#include <bits/stdc++.h>
using namespace std;
vector<int>segTree,nums;
int n;

// we will be storing the index in place of element in the segment tree
void buildTree(int idx,int l,int r)
{
    if(l==r)
    {
        segTree[idx] = r; // stroing the index
        return;
    }
    int mid = (l+r)/2;
    buildTree(2*idx+1,l,mid);
    buildTree(2*idx+2,mid+1,r);
    int leftIndex = segTree[2 * idx + 1];
    int rightIndex = segTree[2 * idx + 2];

    if (nums[leftIndex] >= nums[rightIndex])
        segTree[idx] = leftIndex;
    else
        segTree[idx] = rightIndex;
}
int rmiq(int start,int end,int idx,int l,int r)
{
    // out of bounds
    if(l>end || r<start)
    {
        return -1;// invalid index
    }
    // in range -> return the maximum
    if(start<=l && r<=end)
    {
        return segTree[idx];
    }
    // overlapping -> explore further
    int mid = (l+r)/2;
    int leftIndex = rmiq(start,end,2*idx+1,l,mid);
    int rightIndex = rmiq(start,end,2*idx+2,mid+1,r);
    // If left side is invalid
    if (leftIndex == -1)
        return rightIndex;

    // If right side is invalid
    if (rightIndex == -1)
        return leftIndex;


    if (nums[leftIndex] >= nums[rightIndex])
        return leftIndex;
    else
        return rightIndex;
}
int main()
{
    nums = {10,20,5,15,90,29,72,45,32,8,2,85};
    n = nums.size();

    segTree.resize(4 * n);

    buildTree(0, 0, n - 1);

    int ans = rmiq(2, 6, 0, 0, n - 1);

    cout << "Maximum element = " << nums[ans] << endl;
    cout << "Maximum element index = " << ans << endl;
}
