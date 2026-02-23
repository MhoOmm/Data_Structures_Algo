// brute force - sort and check if equal
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        vector<int> sortasc = nums;
        vector<int> sortdesc = nums;

        sort(sortasc.begin(), sortasc.end());
        sort(sortdesc.begin(), sortdesc.end(), greater<int>());

        return nums == sortasc || nums == sortdesc;
    }
};

// optimal approach - keep a increasing or descreasing flag
class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        int n =nums.size();
        bool inc = true;
        bool des = true;
        for(int i=1;i<n;i++)
        {
            if(nums[i]<nums[i-1])
            {
                inc = false;
            }
            else if(nums[i]>nums[i-1])
            {
                des = false;
            }
        }
        return inc||des;
    }
};