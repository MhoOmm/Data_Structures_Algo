#include<iostream>
using namespace std;


class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0; 
        if (n == 1) return nums[0]; 
        if (n == 2) return max(nums[0],nums[1]);
    
        int prev2= nums[0];
        int prev= max(nums[0], nums[1]);
        int curr1=prev;// if array of size three the the max of both terms should be in it 
        // which is stored in prev
        
        for (int i = 2; i < n-1; i++) {
            int steal = nums[i] + prev2;
            int skip = prev;
            curr1 = max(steal, skip);
            prev2=prev;
            prev=curr1;
        }
        prev2= nums[1];
        prev= max(nums[1], nums[2]);
        int curr2=prev;// if array of size three the the max of both terms should be in it 
        // which is stored in prev 
        
        for (int i = 3; i < n; i++) {
            int steal = nums[i] + prev2;
            int skip = prev;
            curr2 = max(steal, skip);
            prev2=prev;
            prev=curr2;
        }

        return max(curr1,curr2);
        
        
    }
};


int main()
{
    
    return 0;
}