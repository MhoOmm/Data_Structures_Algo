class Solution {
public:
    int maxSum(vector<int>& nums) {
        int n = nums.size();
        int neg = INT_MIN;
        int maxSum = 0;
        unordered_set<int>st;
        
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0){
                if(st.find(nums[i])==st.end())
                {
                    maxSum+=nums[i];
                    st.insert(nums[i]);
                }
            }else{
                neg = max(neg,nums[i]);
            }
        }

        return maxSum==0?neg:maxSum;

    }
};