class Solution {
public:
    typedef long long ll;
    void updateQuery(int i,int l,int r,int idx,vector<long long>&segTree)
    {
        if(l==r)
        {
            // we have reached the index;
            segTree[i] = 1; // mark visited
            return;
        }

        int mid  = (l+r)/2;
        if(idx<=mid)
        {
            updateQuery((2*i)+1,l,mid,idx,segTree);
        }
        else{
            updateQuery((2*i)+2,mid+1,r,idx,segTree);
        }

        segTree[i] = segTree[(2*i)+1]+segTree[(2*i)+2];
    }
    ll findCommon(int start,int end,int idx,int l,int r,vector<long long>&segTree)
    {
        // if out of bound
        if(l>end || r<start)
        {
            return 0;
        }
        // if in bound -> return segTree[i]
        if(start<=l && r<=end){
            return segTree[idx];
        }

        // if overlapping
        int mid = (l+r)/2;
        ll leftCommon = findCommon(start,end,(2*idx)+1,l,mid,segTree);
        ll rightCommon = findCommon(start,end,(2*idx)+2,mid+1,r,segTree);
        return leftCommon+rightCommon;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        vector<ll>segTree(4*n);

        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums2[i]] = i;
        }
        ll ans = 0;
        // traverse in the first array and get the number of elements 
        // which are common in both the arrays on the left of y
        updateQuery(0, 0, n - 1, mp[nums1[0]], segTree);
        for(int i=1;i<n;i++)
        {
            int y = mp[nums1[i]];
            long long leftCommonCount = findCommon(0,y,0,0,n-1,segTree);
            long long notCommonLeft = i-leftCommonCount;
            long long eleRightNums2 = (n-1) - y;
            long long commonRight = eleRightNums2 - notCommonLeft;
            ans += (commonRight)*(leftCommonCount);
            updateQuery(0,0,n-1,y,segTree);
        }
        return ans;
    }
};