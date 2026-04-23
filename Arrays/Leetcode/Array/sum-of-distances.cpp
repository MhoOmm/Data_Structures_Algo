// Brute force approach O(N^2)
class Solution {
public:
    vector<long long> distance(vector<int>& nums) {
        int n = nums.size();
        vector<long long>arr(n,0);

        for(int i=0;i<n;i++)
        {
            long long sum =0;
            for(int j=0;j<n;j++)
            {
                if(i!=j && nums[i]==nums[j])
                {
                    sum+=abs(i-j);
                }
            }
            arr[i] = sum;
        }
        return arr;
    }
};

// Optimal Approach O()
