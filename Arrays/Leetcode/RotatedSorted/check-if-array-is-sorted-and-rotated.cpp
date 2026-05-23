// tc = O(n) & sc= O(n)
class Solution {
public:
    bool check(vector<int>& nums) {
        int n = nums.size();
        vector<int>temp(nums.begin(),nums.end());
        for(int i=0;i<n;i++)
        {
            temp.push_back(nums[i]);
        }

        int count = 1;
        for(int i=0;i<2*n-1;i++)
        {
            if(temp[i]<=temp[i+1])
            {
                count++;
            }else{
                count = 1;
            }
            if(count>=n)
            {
                return true;
            }
        }

        return false;
    }
};

// tc = O(n) & sc= O(1)
class Solution {
public:
    // we check if there is only one peak in the rotated array
    bool check(vector<int>& nums) {
        int n = nums.size();
        int peak = 0;
        for(int i=0;i<n;i++)
        {
            if(nums[i]>nums[(i+1)%n])
            {
                peak++;
            }
        }

        return peak<=1;
    }
};


        