#include<iostream>
using namespace std;

//recursion 
class Solution {
    public:
        int n;
        typedef long long ll;
    
        long long recurr(int idx,int prev,vector<int>&nums)
        {
            if(idx>=n)
            {
                return 0;
    
            }
            ll take = LLONG_MIN;
            if(prev==-1 || (nums[idx]-idx)>=(nums[prev]-prev))
            {
                take=nums[idx]+recurr(idx+1,idx,nums);
            }
    
            ll skip=recurr(idx+1,prev,nums);
    
            return max<long long> (take,skip);
            
    
        }
        long long maxBalancedSubsequenceSum(vector<int>& nums) {
    
            n=nums.size();
    
            ll max=INT_MIN;
            for(int i=0;i<n ;i++)
            {
                if(nums[i]>max)
                {
    
                    max=nums[i];
                }
            }
            if(max<=0)
            {
                return max;
            }
            else{
                return recurr(0,-1,nums);
            }
        }
    };

//memoization approach

// kyunki memoization mein constraints bahut bade hain toh itna bada dp aaray nhi bana sakte 
// also agar mein unordered map bhi use karna chahun to bhi mein nhi use nhi kar sakta leet code tle dedega


// THEREFORE
//bottom approach


class Solution {
    public:
        int n;
        typedef long long ll;
        long long maxBalancedSubsequenceSum(vector<int>& nums) {
    
            n=nums.size();
    
            ll max=INT_MIN;
            for(int i=0;i<n ;i++)
            {
                if(nums[i]>max)
                {
    
                    max=nums[i];
                }
            }
            if(max<=0)
            {
                return max;
            }
            else{
                vector<long long>t(n,1);
                for(int i=0;i<n;i++)
                {
                    t[i]=nums[i];
                }
                long long sumlis=INT_MIN;
                for(int i=0;i<n ;i++)
                {
                    for(int j=0;j<i;j++)
                    {
                        if((nums[i]-i) >= (nums[j]-j))
                        {
                            t[i]=max<long long>(t[i],t[j]+nums[i]);
                            sumlis=max(sumlis,t[i]);
                        }
                    }
                }
    
                return sumlis>max? sumlis:max;
            }
        }
    };


//optimal approach
