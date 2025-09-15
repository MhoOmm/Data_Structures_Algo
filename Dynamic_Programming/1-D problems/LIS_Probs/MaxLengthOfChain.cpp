#include<iostream>
using namespace std;


//recursion and memo 

class Solution {
    public:
       
        int n;
        int dp[1001][1001];
        int recur(int i ,int prev,vector<vector<int>>&pairs)
        {
            if(i>=n)
            {
                return 0;
            }
            
            if(prev!=-1 && dp[i][prev]!=-1)
            {
                return dp[i][prev];
            }
            
            
            int skip=recur(i+1,prev,pairs);
            int take=0;
            if (prev==-1 || pairs[i][0] > pairs[prev][1])
            {
                take=1+recur(i+1,i,pairs);//idhar hi prev ka value ko i 
                //rakh diya to now ab iss subsequence ka prev is i
                        
            }
            
            if(prev!=-1)
            {
                dp[i][prev]=max(take,skip);
            }
            return max(take,skip);
        }
        int findLongestChain(vector<vector<int>>& pairs) {
    
            n=pairs.size();
            memset(dp,-1, sizeof(dp));
            sort(begin(pairs),end(pairs));
            return recur(0,-1,pairs);
        }
    };

// bottom up approach 
class Solution {
    public:
        int findLongestChain(vector<vector<int>>& pairs) {
    
            int n=pairs.size();
            int maxlis=1;
            vector<int>t(n ,1);
            sort(begin(pairs),end(pairs));
            for(int i=0;i<n;i++)
            {
                for(int j=0;j<i;j++)
                {
                    if(pairs[j][1] < pairs[i][0])
                    {
                        t[i]=max(t[i],t[j]+1);
                        maxlis=max( maxlis,t[i]);
                    }
                }
            }
            return maxlis;
    
        }
    };


    