#include<iostream>
using namespace std;

// recursion approach tc:O(2^n)
class Solution {
    public:
        typedef long long ll;
        int n;
        
    
        ll recurr(int idx,bool flag,vector<int>&nums)
        {
            if(idx>=n){
                return 0;
            }
    
            ll skip=recurr(idx+1,flag,nums);
            ll val = nums[idx];
            if(flag == false)
            {
                val = -val;
            }
            ll take=recurr(idx+1,!flag,nums)+val;
            
    
            return max(take,skip);
        }
    
        long long maxAlternatingSum(vector<int>& nums) {
    
            n=nums.size();
            int idx=0;//first inex hoga
            bool flag=true;//initilaly add hoga kyunki 0 index pe hai
            return recurr(idx,flag,nums);
            
        }
    };



//memoization top down 
// take 2d dp as do values change horhi hai
// int dp[100001][2];
    class Solution {
        public:
            typedef long long ll;
            int n;
        
            ll dp[100001][2];//as length of nums can be 100000
            
        
            ll recurr(int idx,bool flag,vector<int>&nums)
            {
                if(idx>=n){
                    return 0;
                }
        
                if(dp[idx][flag]!=-1)
                {
                    return dp[idx][flag];
                }
        
                ll skip=recurr(idx+1,flag,nums);
                ll val = nums[idx];
                if(flag == false)
                {
                    val = -val;
                }
                ll take=recurr(idx+1,!flag,nums)+val;
                
        
                return dp[idx][flag]=max(take,skip);
            }
        
            long long maxAlternatingSum(vector<int>& nums) {
        
                n=nums.size();
                int idx=0;//first inex hoga
                bool flag=true;//initilaly add hoga kyunki 0 index pe hai
                memset(dp,-1,sizeof(dp));
                return recurr(idx,flag,nums);
                
            }
        };



// bottom up approach

class Solution {
    public:
        typedef long long ll;
        int n;
    
        long long maxAlternatingSum(vector<int>& nums) {
    
            n=nums.size();
    
            vector<vector<long long>>dp(n+1,vector<long long>(2,0));
            for(int i=1;i<n+1;i++){
    
                dp[i][0]=max((dp[i-1][1]-nums[i-1]),dp[i-1][0]);
    
                dp[i][1]=max((dp[i-1][0]+nums[i-1]),dp[i-1][1]);
    
    
            }
            return max(dp[n][0],dp[n][1]);
            
        }
    };



    // bottom up approach O(n^2)
class Solution {
public:
    int n;
    int ml;// stores the length of the longest lis;
    int lengthOfLIS(vector<int>& nums) {
        n=nums.size();

        vector<int> t(n,1);

        int ml=1;

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                if(nums[j]<nums[i])
                {
                    t[i]=max(t[i],t[j]+1);
                    ml=max(ml,t[i]);
                }
            }
        }

        return ml;
        
    }
}

