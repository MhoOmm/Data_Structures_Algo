// brute force
class Solution {
public:
    bool isDistinct(int idx,vector<int>&nums){
        unordered_set<int>st;
        for(int i =idx;i<nums.size();i++)
        {
            if(st.find(nums[i])!=st.end()){
                return false;
            }
            st.insert(nums[i]);
        }
        return true;
    }
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        int count =0;
        for(int i=0;i<n;i+=3)
        {
           if(isDistinct(i,nums))
           {
              break;
           } 
           count++;
        }

        return count;
    }
};

// optimised sol
class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st;
        int idx =n;
        for(int i=n-1;i>=0;i--)
        {
           if(st.count(nums[i]))
           {
              return ceil((i+1)/3.0);
              break;
           } 
           st.insert(nums[i]);
        }

        return 0;
    }
};