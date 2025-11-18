class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int n = nums.size();
        int lastidx = -1;

        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) {
                if (lastidx != -1) {
                    if (i - lastidx - 1 < k) {
                        return false;
                    }
                }
                lastidx = i;
            }
        }

        return true;
    }
};
