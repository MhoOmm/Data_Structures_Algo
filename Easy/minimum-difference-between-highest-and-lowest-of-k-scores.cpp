class Solution {
public:
    int minimumDifference(vector<int>& nums, int k) {
        int n = nums.size();
        sort(begin(nums),end(nums));
        int minDif = INT_MAX;

        for(int i=0;i<=n-k;i++){
            int mine = nums[i];
            int maxe = nums[i+k-1];
            minDif = min(minDif,maxe-mine);
        }

        return minDif;
    }
};