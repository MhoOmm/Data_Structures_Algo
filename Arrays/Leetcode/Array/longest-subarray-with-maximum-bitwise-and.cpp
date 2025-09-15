class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int n = nums.size();
        int maxval = 0;
        int result =0;
        int cont =0;
        for(int &num:nums )
        {
            if(num>maxval){
                maxval = num;
                result=0;
                cont= 0;
            }
            if(num ==maxval)
            {
                cont++;
            }else{
                cont = 0;
            }

            result =max(result,cont);
        }

        return result;
    }
};