#include <bits/stdc++.h>
using namespace std;
vector<int> nums,segTree;
vector<int> lazy;
// lazy will be exactly equal to the segTree and will be initialized with zero

void updateRange(int start, int end,int idx,int l,int r,int val)
{
    // check if their is a lazry value of the current node
    if(lazy[idx]!=0)
    {
        segTree[idx] += (l-r+1)*lazy[idx];
        // tell its children about the update
        if(l!=r){
            // not a leaf node
            lazy[2*idx+1] = lazy[idx];
            lazy[2*idx+2] = lazy[idx];
        }

        lazy[idx] = 0; // as the update has been done lazy value reset
        // out of bound index
        if(l>end || r<start)
        {
            return;
        }
        // in bound
        if(start<=l && r<=end){
            segTree[idx] += (r-l+1)*val;
            if(l!=r){
                lazy[2*idx+1] += val;
                lazy[2*idx+2] += val;
            }
            return
        }
        // overlapping
        int mid = (l+r)/2;
        updateRange(start,end,2*idx+1,l,mid,val);
        updateRange(start,end,2*idx+2,mid+1,end,val);
        segTree[idx] = segTree[2*idx+1]+segTree[2*idx+2];
        return;
    }
}
void buildSegTree(int idx,int l,int r)
{
    if(l==r)
    {
        segTree[idx] = nums[l];
        return;
    }
    int mid = (l+r)/2;
    buildSegTree(2*idx+1,l,mid);
    buildSegTree(2*idx+2,mid+1,r);
    segTree[idx] = segTree[2*idx+1] + segTree[2*idx+2];
}