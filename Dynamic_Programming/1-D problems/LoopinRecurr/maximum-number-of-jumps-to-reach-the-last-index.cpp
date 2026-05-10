class Solution {
public:
    int n ;
    int t[1001];
    int solve(vector<int>& nums, int target,int i)
    {
        if(i==n-1)
        {
            return 0; // no further jumps allowed
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int result = INT_MIN;
        for(int j=i+1;j<n;j++)
        {
            if(abs(nums[j]-nums[i]) <= target)
            {
                int step = solve(nums,target,j);
                if(step!=INT_MIN){
                    result = max(result,1+step);
                }
            }
        }

        return t[i] = result;
    }
    int maximumJumps(vector<int>& nums, int target) {
        n = nums.size();
        memset(t,-1,sizeof(t));
        int ans = solve(nums,target,0);
        return ans==INT_MIN?-1:ans;
    }
};