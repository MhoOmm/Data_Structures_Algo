class Solution {
public:
    vector<int>segTree;
    int n;
    void buildTree(int idx,int l,int r,vector<int>& heights)
    {
        if(l==r)
        {
            segTree[idx] = r; // stroing the index
            return;
        }
        int mid = (l+r)/2;
        buildTree(2*idx+1,l,mid,heights);
        buildTree(2*idx+2,mid+1,r,heights);
        int leftIndex = segTree[2 * idx + 1];
        int rightIndex = segTree[2 * idx + 2];
        if (heights[leftIndex] >= heights[rightIndex]){
            segTree[idx] = leftIndex;
        }else{
            segTree[idx] = rightIndex;
        }   
    }
    int rmiq(int start,int end,int idx,int l,int r,vector<int>& heights)
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
        int leftIndex = rmiq(start,end,2*idx+1,l,mid,heights);
        int rightIndex = rmiq(start,end,2*idx+2,mid+1,r,heights);
        // If left side is invalid
        if (leftIndex == -1){
            return rightIndex;
        }
        // If right side is invali
        if (rightIndex == -1)
        {
            return leftIndex;
        }
        if (heights[leftIndex] >= heights[rightIndex]){
            return leftIndex;
        }
        else{
            return rightIndex;
        }     
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        segTree.resize(4*n);
        buildTree(0,0,n-1,heights);
        vector<int>ans;
        for(auto &query:queries)
        {
            int a = query[0];
            int b = query[1];
            // for simplicity -> bob will always be on higher building
            if (a > b)swap(a, b);
            // same building
            if (a == b) {
                ans.push_back(a);
                continue;
            }
            // bob in bigger building
            if (heights[b] > heights[a]) {
                ans.push_back(b);
                continue;
            }
            int result = -1;
            if(b>=n-1 || a>=n-1)
            {
                ans.push_back(result);
                continue; 
            }
            int maxEle = max(heights[a],heights[b]);
            int l=max(a,b)+1;
            int r=n-1;

            while(l<=r)
            {
                int mid = (l+r)/2;
                int rmi = rmiq(l, mid, 0, 0, n - 1, heights);
                if(rmi != -1 && heights[rmi] > maxEle )
                {
                    result = rmi;
                    r = mid-1;
                }else
                {
                    l = mid+1;
                }
            } 
            ans.push_back(result);
        }
        return ans;
    }
};