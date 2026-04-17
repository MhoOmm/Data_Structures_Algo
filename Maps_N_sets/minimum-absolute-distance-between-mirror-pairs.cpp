//  Brute-force approach O(n^2)
//  TLE 

class Solution {
public:
    int reverse(int n)
    {
        int num = 0;
        while(n>0){
            int r = n%10;
            num = num*10+r;
            n = n/10;
        }

        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,vector<int>>mp;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            mp[nums[i]].push_back(i);
        }

        int minDist = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int rev = reverse(nums[i]);
            if(mp.find(rev)!=mp.end())
            {
                for(auto &idx:mp[rev])
                {
                    if(idx!=i && i<idx)
                    {
                        int diff = abs(idx-i);
                        minDist = min(minDist,diff);
                    }
                }
            } 
        }

        return minDist==INT_MAX?-1:minDist;
    }
};

// optimised approach - single pass
class Solution {
public:
    int reverse(int n)
    {
        int num = 0;
        while(n>0){
            int r = n%10;
            num = num*10+r;
            n = n/10;
        }

        return num;
    }
    int minMirrorPairDistance(vector<int>& nums) {
        unordered_map<int,int>mp;
        int n = nums.size();

        int minDist = INT_MAX;
        for(int i=0;i<n;i++)
        {
            int rev = reverse(nums[i]);
            if(mp.find(nums[i])!=mp.end())
            {
                int diff = abs(i-mp[nums[i]]);
                minDist = min(minDist,diff);
            }

            mp[rev] = i;
        }

        return minDist==INT_MAX?-1:minDist;
    }
};