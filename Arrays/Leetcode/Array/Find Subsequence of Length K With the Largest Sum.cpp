
// O(nlogn) TC approach
// O(n) SC
class Solution {
public:
    vector<int> maxSubsequence(vector<int>& nums, int k) {
        int n = nums.size();
        vector<pair<int,int>>arr(n);

        for(int i=0;i<n;i++)
        {
            arr[i]=make_pair(i,nums[i]);
        }

        auto lambda = [](auto &p1,auto &p2){
            return p1.second>p2.second;
        };

        sort(begin(arr),end(arr),lambda);

        // to sort the k elements out

        sort(begin(arr),begin(arr)+k);

        vector<int>result(k);
        for(int i = 0;i<k;i++)
        {
            result[i]=arr[i].second;
        }

        return result;
    }
};


// better approach (partial sorting)

