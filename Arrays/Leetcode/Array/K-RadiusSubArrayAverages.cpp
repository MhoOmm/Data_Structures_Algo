class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<long long >prefixSum(n);
        vector<int> result(n,-1);
        prefixSum[0]=nums[0];
        if (k == 0) return nums;
        if (n < 2 * k + 1) return result;
        for(int i=1;i<n;i++)
        {
            prefixSum[i]=prefixSum[i-1]+nums[i];
        }

        

        for(int i = k;i<n-k;i++)
        { 
            int left = i-k ;
            int right = i+k;

            long long total = prefixSum[right] - (left > 0 ? prefixSum[left - 1] : 0);

            result[i] = total/(2*k+1);
        }

        return result;
    }
};


// Sliding Window Approach


class Solution {
public:
    vector<int> getAverages(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> result(n, -1);
        if (k == 0) return nums;
        if (n < 2 * k + 1) return result;

        int left = 0;
        int right = 2 * k;
        int i = k;  // center of the first window
        long long windowSum = 0;
        int count = 2 * k + 1;

        // Sum for the initial window
        for (int j = left; j <= right; j++) {
            windowSum += nums[j];
        }

        result[i++] = windowSum / count;
        right++;

        while (right < n) {
            windowSum += nums[right];
            windowSum -= nums[left];
            result[i++] = windowSum / count;
            left++;
            right++;
        }

        return result;
    }
};