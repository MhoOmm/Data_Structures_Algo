
#include<iostream>
using namespace std;

// recurrsion
class Solution {
    public:
        int n;
        int recur(int i ,int prev,vector<int>&nums)
        {
            if( i>=n)
            {
                return 0;
            }
    
            int skip=recur(i+1,prev,nums);
            int take=0;
            if (prev==-1 || nums[i] > nums[prev])
            {
                take=1+recur(i+1,i,nums);//idhar hi prev ka value ko i 
                //rakh diya to now ab iss subsequence ka prev is i
                
            }
            return max(take,skip);
    
        }
        int lengthOfLIS(vector<int>& nums) {
            n=nums.size();
            int prev=-1;
            memset(dp,-1, sizeof(dp));
            return recur(0,-1,nums);
            
        }
    };


// topdown memoization
class Solution {
    public:
        int n;
        int dp[2501][2501];
        int recur(int i ,int prev,vector<int>&nums)
        {
            if( i>=n)
            {
                return 0;
            }
    
            if(prev!=-1 && dp[i][prev]!=-1)
            {
                return dp[i][prev];
            }
    
    
            int skip=recur(i+1,prev,nums);
            int take=0;
            if (prev==-1 || nums[i] > nums[prev])
            {
                take=1+recur(i+1,i,nums);//idhar hi prev ka value ko i 
                //rakh diya to now ab iss subsequence ka prev is i
                
            }
    
            if(prev!=-1)
            {
                dp[i][prev]=max(take,skip);
            }
            return max(take,skip);
    
        }
        int lengthOfLIS(vector<int>& nums) {
            n=nums.size();
            int prev=-1;
            memset(dp,-1, sizeof(dp));
            return recur(0,-1,nums);
            
        }
    };

// bottom up approach
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
        };
