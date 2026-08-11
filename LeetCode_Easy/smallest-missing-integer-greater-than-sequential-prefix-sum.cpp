class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        int seqSum = nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i-1]+1 == nums[i])
            {
                seqSum += nums[i];
            }
            else{
                break;
            }
        }
        while(st.count(seqSum))
        {
            seqSum++;
        }
        return seqSum;
    }
};