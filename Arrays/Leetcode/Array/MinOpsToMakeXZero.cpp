// recursion +memo gives tle
class Solution {
public:
    int n;
    map<pair<int, int>, int> memo;

    int solve(int i, int j, vector<int>& nums, int x) {
        if (x == 0) return 0;
        if (x < 0 || i > j) return INT_MAX;

        pair<int, int> key = {i, x}; 
        if (memo.find(key) != memo.end()) return memo[key];

        int left = solve(i + 1, j, nums, x - nums[i]);
        int right = solve(i, j - 1, nums, x - nums[j]);

        int res = INT_MAX;
        if (left != INT_MAX) res = min(res, 1 + left);
        if (right != INT_MAX) res = min(res, 1 + right);

        memo[key] = res;
        return res;
    }

    int minOperations(vector<int>& nums, int x) {
        n = nums.size();
        memo.clear();
        int ans = solve(0, n - 1, nums, x);
        return (ans == INT_MAX) ? -1 : ans;
    }
};


// my code 
class Solution {
public:
    int n;
    int minc;
    int solve(int i,int j,vector<int>&nums,int count,int x)
    {
        if(x==0)
        {
          return 0;  
        }
        if (x < 0 || i > j) return INT_MAX;
        int right=solve(i,j-1,nums,count+1,x-nums[j]);
        int left=solve(i+1,j,nums,count+1,x-nums[i]);

        int res = INT_MAX;
        if (left != INT_MAX) res = min(res, 1 + left);
        if (right != INT_MAX) res = min(res, 1 + right);

        return res;
    }
    int minOperations(vector<int>& nums, int x) {
        n=nums.size();
        int minc=*min_element(begin(nums),end(nums));
        if(minc>x)
        {
            return -1;
        }
        int count=0;
        int ans=solve(0,n-1,nums,count,x);
        if(ans==INT_MAX){
            return -1;
        }
        return ans;
    }
};

// optimised -using a map
class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n =nums.size();
        int sum=0;
        unordered_map<int,int>mp;
        mp[0]=-1;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            mp[sum]=i;
        }
        if(sum<x)
        {
            return -1;
        }
        int subarrsum=sum-x;
        sum=0;
        int longestsubarr=INT_MIN;
        for(int i=0;i<n;i++)
        {
            sum+=nums[i];
            int finds=sum-subarrsum;
            if(mp.find(finds)!=mp.end())
            {
                int idx=mp[finds];
                longestsubarr=max(longestsubarr,i-idx);
            }
        }
        return longestsubarr==INT_MIN?-1:n-longestsubarr;
    }
};