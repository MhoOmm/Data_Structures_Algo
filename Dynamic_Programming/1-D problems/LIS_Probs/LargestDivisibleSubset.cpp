#include<iostream>
using namespace std;

//recurr approach
class Solution {
    public:
    
        void recur(int idx,vector<int>&nums,vector<int>&temp,vector<int>&ans,int prev)
        {
            if(idx>=nums.size())//base case
            {
                if(temp.size() > ans.size())
                {
                    ans=temp;
                }
                return ;
            }
    
            //take
            if(prev==-1 || nums[idx]%prev==0)
            {
                temp.push_back(nums[idx]);
                recur(idx+1,nums,temp,ans,nums[idx]);
                temp.pop_back();//as in recursion we to get the skip 
                //option also to ye hata dega
            }
    
            //skip 
            recur(idx+1,nums,temp,ans,prev);
    
    
    
        }
        vector<int> largestDivisibleSubset(vector<int>& nums) {
    
            sort(begin(nums),end(nums));
    
            vector<int>temp;
            vector<int>ans;
    
            int prev=-1;
            recur(0,nums,temp,ans,prev);
    
            return ans;
        }
    };

//memoization also gives tle
//but this solution is valid in interviews



//bottom up approach

class Solution {
    public:
        vector<int> largestDivisibleSubset(vector<int>& nums) {
    
            int n=nums.size();
            
            sort(begin(nums),end(nums));
            // for getting to the answer
            vector<int>t(n,1);
            vector<int>prev_idx(n,-1);
    
            int maxlis=1;
            int bigidx=0;
    
            for(int i=1;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
    
                    if(nums[i]%nums[j]==0)
                    {
                        if(t[i]<t[j]+1)
    
                        {
                            t[i]=t[j]+1;
                            prev_idx[i]=j;
                        }
    
                        if(t[i]>maxlis)
                        {
                            maxlis=t[i];
                            bigidx=i;
                        }
    
                    }
    
                }
            }
    
            // for storing the ans
            vector<int>ans;
    
            while(bigidx!=-1)
            {
                ans.push_back(nums[bigidx]);
                bigidx=prev_idx[bigidx];
            }
            
            reverse(ans.begin(),ans.end());
            return ans;
    
    
        }
    };