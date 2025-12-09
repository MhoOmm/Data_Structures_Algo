class Solution {
public:
    int M = 1e9+7;
    int specialTriplets(vector<int>& nums) {

        int n = nums.size();
        unordered_map<int,int>mp_left;
        unordered_map<int,int>mp_right;
        int count =0;
        for(auto &num:nums){
            mp_right[num]++;
        }
        for(auto &num:nums)
        {
            int xd = num*2;
            mp_right[num]--;
            int left = mp_left[xd];
            int right = mp_right[xd];
            count  = (count+(1LL*left*right))%M;
            mp_left[num]++;
        }

        return count; 
    }
};