class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>arr(n,0);
        for(auto q:queries)
        {
            int s=q[0];
            int e=q[1];
            arr[s]+=1;
            if(e+1<n)
            {
                arr[e+1]-=1;
            }
        }
        vector<int> result(n, 0);
        int sum = 0;
        for(int i = 0; i < n; i++) {
            sum += arr[i];
            result[i] = sum;
        }

        for(int i = 0; i < n; i++) {
            if(result[i] < nums[i]) {
                return false;
            }
        }

        return true;
    }
};