//recursion + memoization
//tc: o(n^2)
class Solution {
public:
    int t[10001];
    bool solve(int i,vector<int>&nums)
    {
        if(i>=nums.size()-1)
        {
            return true;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        for(int j=1;j<=nums[i];j++)
        {
            if(solve(i+j,nums))
            {
                return t[i] = true;
            }
        }
        return t[i] = false;
    }
    bool canJump(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};

//bottom up
//tc: o(n^2)
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            vector<bool>t(n,false); 
    
            t[0]=true;
            for(int i=1;i<=n;i++)
            {
                for(int j=i-1;j>=0;j--)
                {
                    if(t[j]==true && nums[j]+j>=i)
                    {
                        t[i]=true;
                        break;
                    }
                }
            } 
            return t[n-1];      
        }
    };

//better approach
//tc: o(n)
// o(n) approach
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int maxReach = 0;
        for(int i=0;i<n;i++)
        {
            if(i>maxReach)
            {
                return false;
            }
            maxReach = max(maxReach,nums[i]+i);
        } 

        return true;
    }
};