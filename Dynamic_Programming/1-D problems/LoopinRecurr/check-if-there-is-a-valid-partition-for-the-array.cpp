class Solution {
public:
    int t[100001];
    bool checkValid(vector<int>&nums,int start,int end )
    {
        int l = end-start+1;
        if(l==2)
        {
            return nums[start]==nums[start+1];
        }
        if(l == 3)
        {
            // 3 equal elements
            if(nums[start]==nums[start+1] &&nums[start+1]==nums[start+2])
            {
                return true;
            }
            // 3 consecutive increasing
            if(nums[start]+1==nums[start+1] && nums[start+1]+1==nums[start+2])
            {
                return true;
            }
        }
        return false;
    }
    bool solve(vector<int>&nums,int i,int n){
        if(i>=n)
        {
            return true;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        for(int j=i;j<n && j<i+3;j++)
        {
            if(checkValid(nums,i,j))
            {
                if(solve(nums,j+1,n))
                {
                    return t[i]=true;
                }
            }
        }

        return t[i]=false;
    }
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        memset(t,-1,sizeof(t));
        return solve(nums,0,n);
    }
};