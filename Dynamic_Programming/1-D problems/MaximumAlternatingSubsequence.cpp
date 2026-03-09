#include<iostream>
using namespace std;

// Recursion approach another approach - cant be memoized


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
    long long  t[100001][2];
    long long solve(vector<int>& nums,int i,bool isOdd)
    {
        if(i>=nums.size())
        {
            return 0;
        } 
        if(t[i][isOdd]!=-1)
        {
            return t[i][isOdd]; 
        }
        long long skip = solve(nums,i+1,isOdd);
        long long val = nums[i];
        if(isOdd)
        {
            val = -1*val;
        }
        long long take = val + solve(nums,i+1,!isOdd);
        return t[i][isOdd] = max(take,skip);  
    }
    long long maxAlternatingSum(vector<int>& nums) {
        memset(t,-1, sizeof(t));
        return solve(nums,0,false);
    }
};
// bottom up approach

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<long long>> t(n+1,vector<long long>(2,0));

        t[0][1] = nums[0];
        t[0][0] = 0;

        for(int i=1;i<n;i++)
        {
            t[i][0] = max((t[i-1][1]-nums[i]),t[i-1][0]);
            t[i][1] = max((t[i-1][0]+nums[i]),t[i-1][1]);
        }
        return max(t[n-1][0],t[n-1][1]);
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

