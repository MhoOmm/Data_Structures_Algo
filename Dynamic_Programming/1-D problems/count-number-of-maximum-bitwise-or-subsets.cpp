class Solution {
public:
    int n ;
    int t[16][100000];
    int solve(int i, int curror,vector<int>& nums,int maxor,vector<vector<int>>&t){
        if(i>=n)
        {
            if(curror == maxor)
            {
                return 1;
            }else{
                return 0;
            }
        }

        if(t[i][curror]!=-1)
        {
            return t[i][curror];
        }

        // take
        int take = solve(i+1,curror|nums[i],nums,maxor,t);
        // skip
        int skip = solve(i+1,curror,nums,maxor,t);

        return t[i][curror]=take+skip;
    }
    int countMaxOrSubsets(vector<int>& nums) {
        n = nums.size();
        int maxor=0;
        for(int i = 0;i<n;i++)
        {
            maxor|=nums[i];
        }

        vector<vector<int>>t(n+1, vector<int>(maxor+1, -1));

        int curror = 0;
        return solve(0,curror,nums,maxor,t);
    }
};