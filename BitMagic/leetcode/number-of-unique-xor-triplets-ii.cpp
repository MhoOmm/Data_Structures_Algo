class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        int t = 1;
        int maxele = *max_element(nums.begin(),nums.end());
        while (t <= maxele) {
            t *= 2;
        }
        vector<bool>s1(t,false);
        vector<bool>s2(t,false);
        for(int i=0;i<n;i++){
            for(int j=i;j<n;j++){
                s1[nums[i]^nums[j]] = true;
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<t;j++)
            {
                if(s1[j])
                {
                    s2[nums[i]^j] = true;
                }
            }
        }

        // calculating unique
        int count =0;
        for(int i=0;i<t;i++){
            if(s2[i])
            {
                count++;
            }
        }
        return count;
    }
}; 