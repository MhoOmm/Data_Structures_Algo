#include<iostream>
using namespace std;
//recursion approach

class Solution {
public:
    int robbing(vector<int>&nums,int n,int k)
    {
        if(n==0)
        {
            return nums[0];
        }
        if(n<=0){
            return 0;
        }
        int steal=nums[n]+robbing(nums,n-2,k);
        int skip=robbing(nums,n-1,k);
        return max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int k=nums.size();
        int n=k-1;
        return robbing(nums,n,k);
        
    }
};

// top down approach

class Solution {
public:
    int robbing(vector<int>&nums,int n,int k,vector<int>&dp)
    {
        if(n==0)
        {
            return nums[0];
        }
        if (n==1){
            return max(nums[0],nums[1]);
        }
        if (dp[n]!=-1)
        {
            return dp[n];
        }
        int steal=nums[n]+robbing(nums,n-2,k,dp);
        int skip=robbing(nums,n-1,k,dp);
        return dp[n]=max(steal,skip);
    }
    int rob(vector<int>& nums) {
        int k=nums.size();
        int n=k-1;
        vector<int>dp(n+1,-1);

        return robbing(nums,n,k,dp);
        
    }
};

//bottom up approach 
class Solution {
public:   
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 
        if (n == 1) return nums[0]; 
        
        vector<int> dp(n, -1);
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        
        for (int i = 2; i < n; i++) {
            int steal = nums[i] + dp[i - 2];
            int skip = dp[i - 1];
            dp[i] = max(steal, skip);
        }
        return dp[n - 1];
    }
};

// optimization 
class Solution {
public:   
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 
        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0],nums[1]);
    
        int prev2= nums[0];
        int prev= max(nums[0], nums[1]);
        int curr=0;
        
        for (int i = 2; i < n; i++) {
            int steal = nums[i] + prev2;
            int skip = prev;
            curr = max(steal, skip);
            prev2=prev;
            prev=curr;
        }
        return curr;
    }
};

int main()
{
    
    return 0;
}