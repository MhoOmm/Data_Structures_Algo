class Solution {
public:
    long long t[201][201][201];
    int mod = 1e9+7;
    int solve(vector<int>& nums,int i,int gc1,int gc2)
    {
        if(i==nums.size())
        { 
            bool not_zero = (gc1!=0 && gc2!=0);
            bool gcd_equal = (gc1==gc2) ; 

            return not_zero && gcd_equal ;
        }

        if(t[i][gc1][gc2]!=-1)
        {
            return t[i][gc1][gc2];
        }

        int take1 = solve(nums,i+1,gcd(gc1,nums[i]),gc2);
        int take2 = solve(nums,i+1,gc1,gcd(gc2,nums[i]));
        int skip = solve(nums,i+1,gc1,gc2);

        return t[i][gc1][gc2] = (0LL + take1 + take2 + skip)%mod;
    }
    int subsequencePairCount(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(nums,0,0,0);
    }
};