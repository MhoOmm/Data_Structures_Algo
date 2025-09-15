recur+memo

class Solution {
public:
    int m;
    int n;
    int t[500][500];
    int solve(int i,int j,vector<int>& nums1, vector<int>& nums2)
    {
        if(i>=m || j>=n)
        {
            return 0;
        }
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        if(nums1[i]==nums2[j])
        {
            return t[i][j]=1+solve(i+1,j+1,nums1,nums2);
        }
        int rightj=solve(i,j+1,nums1,nums2);
        int lefti=solve(i+1,j,nums1,nums2);

        return t[i][j]=max(rightj,lefti);
    }
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        m=nums1.size();
        n=nums2.size();
        memset(t,-1,sizeof(t));
        return solve(0,0,nums1,nums2);
        
    }
};

//bottom up 
class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int m=nums1.size();
        int n=nums2.size();
        vector<vector<int>>t(m+1,vector<int>(n+1,0));
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(nums1[i-1]==nums2[j-1])
                {
                    t[i][j]=1+t[i-1][j-1];
                }else{
                    int right=t[i][j-1];
                    int down=t[i-1][j];
                    t[i][j]=max(right,down);
                }
            }
        }
        return t[m][n];
    }
};