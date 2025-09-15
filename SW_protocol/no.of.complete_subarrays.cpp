
#include<iostream>
using namespace std;
#include <vector>
class Solution {
    public:
        int countCompleteSubarrays(vector<int>& nums) {
    
            unordered_map<int,int>ump;
            int n=nums.size();
            unordered_set<int>st(nums.begin(),nums.end());
            int c=st.size();
    
            int res=0;
            int i=0;
            int j=0;
    
            while(j<n)
            {
                ump[nums[j]]++;
    
                while(ump.size() == c) {
                    res += (n-j);
    
                    ump[nums[i]]--;
                    if(ump[nums[i]] == 0) {
                        ump.erase(nums[i]);
                    }
                    i++;
                }
                
                j++;
            }
            return res;
             
        }
       
    
    };