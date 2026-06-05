class Solution {
public:
    int t[501][501];
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2)
    {
        if(i==nums1.size() || j==nums2.size()) // no more exploring
        {
            return -1e9;//if every time skip then we have to return a very small value
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }

        // take both i and j -> add to dot-product
        // can become very small due to -1e9 so we have to do max(0,solve)
        int takeB = (nums1[i]*nums2[j]) + max(0,solve(i+1,j+1,nums1,nums2));
        // dont take this i
        int skipi = solve(i+1,j,nums1,nums2);
        // dont take this j
        int skipj = solve(i,j+1,nums1,nums2);

        return t[i][j] = max({takeB,skipi,skipj});
    }
    int maxDotProduct(vector<int>& nums1, vector<int>& nums2) {
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
    }
};