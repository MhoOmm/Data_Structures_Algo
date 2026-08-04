#include <bits/stdc++.h>
using namespace std;
vector<int> nums,segMin,segMax;
vector<int> lazy;

void buildTree(int idx,int l,int r)
{
    if(l==r)
    {
        segMin[idx] = nums[r];
        segMax[idx] = nums[r]; // number init
        return;
    }

    int mid = (l+r)/2;
    buildTree(2*idx+1,l,midx);
    buildTree(2*idx+2,mid+1,r);
    segMax[idx] = max(segTree[2*idx+1],segTree[2*idx+2]);
    segMin[idx] = min(segTree[2*idx+1],segTree[2*idx+2]);
}

void propagate(int idx,int l,int r,int val)
{
    if(lazy[i]!=0)
    {
        // it has been updated
        segMin[idx] += val;
        segMax[idx] += val;

        // update the children
        if(l!=r)
        {
            // not a leaf node
            lazy[2*idx+1] = lazy[idx];
            lazy[2*idx+1] = lazy[idx];
        }
        // unmark it -> make it zero
        lazy[idx] = 0;
    }
}

void rangeUpdate(int start,int end,int idx,int l,int r,int val)
{
    // check if the lazy idx has been updated before
    propagate(idx,l,r,val);
    // if out of bound
    if(l>end || r<start)
    {
        return;
    }
    // in bound
    if(start<=l && r<=end)
    {
        lazy[idx] += val;
        propagate(idx,l,r);
    }
    // overlapping
    int mid = (l+r)/2;
    rangeUpdate(start,end,2*idx+1,l,mid,val);
    rangeUpdate(start,end,2*idx+2,mid+1,r,val);
    segMax[idx] = max(segTree[2*idx+1],segTree[2*idx+2]);
    segMin[idx] = min(segTree[2*idx+1],segTree[2*idx+2]);
    return;
}