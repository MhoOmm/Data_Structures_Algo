// Top Down - Apporach (Dp)
class Solution {
public:
    int n;
    int t[10001];
    int solve(int i,vector<int>&nums)
    {
        if(i>=n-1)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int result = INT_MAX;
        for(int j=1;j<=nums[i];j++)
        {
            int step = solve(i+j,nums);
            if(step!=INT_MAX)
            {
                result = min(result,1+step);
            }
        }
        return t[i] = result;
    }
    int jump(vector<int>& nums) {
        n = nums.size();
        if(n==1)
        {
            return 0;
        }
        memset(t,-1,sizeof(t));
        return solve(0,nums); 
    }
};

// Bottom up Approach (DP)
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();

        vector<int>t(n,INT_MAX);
        t[0] = 0;

        for(int i = 0; i<n;i++)
        {
            if (t[i]==INT_MAX){
                continue;
            }
            for(int j = i+1;j<=min(n - 1, i + nums[i]);j++)
            {
                t[j] = min(t[j],t[i]+1);
            }
        }

        return t[n-1];
        
    }
};

// greedy approach
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        int l =0;
        int r =0;
        int far = 0;
        int jump =0;
        while(r<n-1)
        {
            int farthest = 0;
            for(int i=l;i<=r;i++)
            {
                farthest = max(farthest,i+nums[i]);
            }
            l = r+1;
            r = farthest;
            jump++;
        }

        return jump;
    }
};