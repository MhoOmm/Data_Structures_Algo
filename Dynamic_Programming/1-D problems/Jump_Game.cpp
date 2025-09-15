//recursion + memoization
//tc: o(n^2)
class Solution {
    public:
        int n;
        int t[100001];
        bool solve(int i,int n,vector<int>& nums)
        {
            if(i>=n-1)
            {
                return true;
            }
            if(t[i]!=-1)
            {
                return t[i];
            }
            for(int j=1;j<=nums[i];j++){
            
                if(solve(i+j,n,nums)){
                    return t[i]=true;
                }
            }
            return t[i]=false;
        }
        bool canJump(vector<int>& nums) {
            n=nums.size();
            memset(t,-1,sizeof(t));
            return solve(0,n,nums);
            
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
class Solution {
    public:
        bool canJump(vector<int>& nums) {
            int n=nums.size();
            int maxreach=0;
            
            for(int i=0;i<n;i++){
                
                if(i>maxreach)
                {
                    return false;
                }
                maxreach=max(maxreach,nums[i]+i);
            }
            return true;
        }
    };