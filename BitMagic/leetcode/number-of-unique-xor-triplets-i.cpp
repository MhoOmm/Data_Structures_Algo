class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();
        if(n==1)return 1;
        if(n==2) return 2;

        int div = 1;
        while(div<=n)
        {
            div*=2;
        }
        return div;
    }
};