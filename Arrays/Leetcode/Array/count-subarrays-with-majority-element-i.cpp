// brute force - O(n^3) give tle
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int countT =0;
                for(int k=i;k<=j;k++)
                {
                    if(nums[k]==target)
                    {
                        countT ++;
                    }
                }

                if(countT>(j-i+1)/2)
                {
                    result++;
                }
            }
        }

        return result;
    }
};

// better approach - O(n^2) - on the flu counting of the target element

class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int result = 0;
        int n = nums.size();

        for(int i=0;i<n;i++)
        {
            int countT = 0;
            for(int j=i;j<n;j++)
            {
                if(nums[j]==target)
                {
                    countT += 1;
                }

                if(countT>(j-i+1)/2)
                {
                    result++;
                }
            }
        }

        return result;
    }
};

// optimised approach - alsi the solution for part 2
class Solution {
public:
   typedef long long ll;
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        unordered_map<int,int>mp;
        mp[0] = 1;
        int cumsum =0;
        ll valid = 0;
        ll result = 0;
        for(int j=0;j<n;j++)
        {
            if(nums[j]==target)
            {
                valid += mp[cumsum];
                cumsum+=1;
            }else{
                cumsum-=1;
                valid -= mp[cumsum];
            }

            mp[cumsum] += 1;
            result += valid;
        }
        return result;
    }
};