// brute force
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int>st(nums.begin(),nums.end());
        for(int i =0;i<=n;i++)
        {
            if(st.find(i)==st.end())
            {
                return i;
            }
        }
        return -1;
    }
};

// gauss method
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum = n*(n+1)/2;
        int act = accumulate(nums.begin(),nums.end(),0);
        return sum-act;
    }
};