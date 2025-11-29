class Solution {
public:
    int minOperations(vector<int>& nums, int k) {

        int n = nums.size();

        int sum =  accumulate(nums.begin(),nums.end(),0);
        int count=0;

        if(sum<k)
        {
            return sum;
        }

        while(sum%k!=0)
        {
            sum--;
            count++;
        }

        return count;
        
    }
};