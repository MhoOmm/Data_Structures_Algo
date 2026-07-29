#include <bits/stdc++.h>
using namespace std;
vector<int> nums,segTree;

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