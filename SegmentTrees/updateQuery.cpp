#include <bits/stdc++.h>
using namespace std;
vector<int> nums,segTree;
// efficient update only visit the nodes which should be changed
// we traverse the height of the tree -> O(log(n)) tc 
void updateQuery (int idx,int val,int i,int l,int r)
{
    if(l==r)
    {
        segTree[i] = val;
        return;
    }
    int mid = (l+r)/2;
    if(idx<=mid)
    {
        // element present in the left child
        updateQuery(idx,val,2*i+1,l,mid);
    }
    else{
        // element present in the right child
        updateQuery(idx,val,2*i+2,mid+1,r);
    }
    segTree[i] = segTree[2*i+1] + segTree[2*i+2];
}