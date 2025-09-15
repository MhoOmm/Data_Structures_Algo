class Solution {
public:
    int candivide(int mid, vector<int>& nums) {
        int sum = 0;
        for (int num : nums) {
            sum += (num + mid - 1) / mid;
        }
        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int start = 1;
        int endi = *max_element(nums.begin(), nums.end());
        int result = endi;

        while (start <= endi) {
            int mid = start + (endi - start) / 2;
            if (candivide(mid, nums) <= threshold) {
                result = mid;
                endi = mid - 1;
            } else {
                start = mid + 1;
            }
        }
        return result;
    }
};