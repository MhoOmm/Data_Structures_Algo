class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1;
        sort(begin(nums),end(nums));
        int min = nums[0];
        for(int i=1;i<n;i++)
        {
            if(nums[i]-min > k)
            {
                count++;
                min=nums[i];
            }
        }

        return count;
    }
};