class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int>result;
        for(auto &num:nums)
        {
            while(!result.empty())
            {
                int backend = result.back();
                int curr  = num;

                int Gcd = gcd(curr,backend);

                if(Gcd==1)
                {
                    break;
                }
                result.pop_back();
                int lcm = backend/Gcd * curr;
                num = lcm;
            }
            result.push_back(num);
        }

        return result;
    }
};