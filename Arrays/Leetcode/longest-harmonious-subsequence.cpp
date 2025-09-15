// using normal double for loop
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        int result = 0;
        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {
            int count = 1;
            bool valid=false;
            for (int j = i + 1; j < n; j++) {
                if (nums[j] - nums[i] == 1) {
                    count++;
                    valid = true;
                } else if (nums[j] == nums[i]) {
                    count++;
                } else if (nums[j] - nums[i] > 1) {
                    break;
                }
            }
            if(valid)
            {
                result = max(result, count);
            }  
        }

        return result;
    }
};



// using hash map 
class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(int &num:nums)
        {
            mp[num]++;
        }
        int result = 0;

        for(int &num:nums)
        {
            int l = num;
            int r = num+1;
            if(mp.count(r))
            {
                result= max(result,mp[l]+mp[r]);
            }
        }

        return result;


    }
};