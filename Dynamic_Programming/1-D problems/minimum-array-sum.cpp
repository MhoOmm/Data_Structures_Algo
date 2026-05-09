// top down approach
class Solution {
public:
    int t[101][101][101];
    int solve(vector<int>&nums,int op1,int op2,int k,int i)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(t[i][op1][op2]!=-1)
        {
            return t[i][op1][op2];
        }

        // do op1
        int ans1 = INT_MAX;
        if(op1>0)
        {
            int temp = nums[i];
            temp = (temp+1)/2;
            ans1 = temp + solve(nums,op1-1,op2,k,i+1);
        }
        // do op2
        int ans2 = INT_MAX;
        if(op2>0 && nums[i]>=k)
        {
            int temp = nums[i]-k;
            ans2 = temp + solve(nums,op1,op2-1,k,i+1);
        }
        // do both if allowed
        int ans3 = INT_MAX;
        int ans4 = INT_MAX;
        if(op1>0 && op2>0 && nums[i]>=k)
        {
            // op1->op2
            int temp = nums[i];
            temp = (temp+1)/2;
            if(temp >= k)
            {
                temp = temp-k;
                ans3 = temp + solve(nums,op1-1,op2-1,k,i+1);
            }
            // op2->op1
            temp = nums[i];
            temp = temp-k;
            temp = (temp+1)/2;
            ans4 =temp + solve(nums,op1-1,op2-1,k,i+1);
        }
        // do none
        int ans5 = nums[i] + solve(nums,op1,op2,k,i+1);

        return t[i][op1][op2] = min({ans1,ans2,ans3,ans4,ans5});
    }
    int minArraySum(vector<int>& nums, int k, int op1, int op2) {
        memset(t,-1,sizeof(t));
        return solve(nums,op1,op2,k,0);
    }
};