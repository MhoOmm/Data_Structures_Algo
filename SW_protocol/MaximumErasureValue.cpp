// sw Protocol Approach
class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n = nums.size();
        int i = 0 ;
        int j= 0;
        unordered_set<int>st;
        int sum = 0;
        int ans = 0;

        while(j<n)
        {
            if(!st.count(nums[j]))
            {
                st.insert(nums[j]);
                sum+=nums[j];
                ans = max(ans,sum);
                j++;
            }else{
                while(i<n && st.count(nums[j])){
                    sum -= nums[i];
                    st.erase(nums[i]);
                    i++;
                }
            }
        }

        return ans;
    }
};


// Slightly better Approach