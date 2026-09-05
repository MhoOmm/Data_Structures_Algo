class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        int l_min_idx = 0;
        int l_max_idx = 0;
        int r_min_idx = 0;
        int r_max_idx = 0;

        // left side iteration
        int step = 1;
        for(int i=0;i<n;i++)
        {
            if(minEle > nums[i])
            {
                minEle = nums[i];
                l_min_idx = step;
            }
            if(maxEle < nums[i])
            {
                maxEle = nums[i];
                l_max_idx = step;
            }
            step++;
        }
        step = 1;
        for (int i = n - 1; i >= 0; i--) {
            if (nums[i] == minEle) {
                r_min_idx = step;
            }

            if (nums[i] == maxEle) {
                r_max_idx = step;
            }

            step++;
        }
        //Both from left
        int bothLeft = max(l_min_idx, l_max_idx);

        //Both from right
        int bothRight = max(r_min_idx, r_max_idx);

        //One from each side
        int minLeftMaxRight = l_min_idx + r_max_idx;
        int maxLeftMinRight = l_max_idx + r_min_idx;

        return min({
            bothLeft,
            bothRight,
            minLeftMaxRight,
            maxLeftMinRight
        });

    }
};