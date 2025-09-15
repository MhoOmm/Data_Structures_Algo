class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int>mp;
        unordered_set<int>st;
        for(auto &i:arr)
        {
            mp[i]++;
        }

        for(auto &it:mp)
        {
            int freq=it.second;
            if(st.find(freq)!=st.end())
            {
                return false;
            }
            st.insert(freq);
        
        }
        return true;
    }
};



//aproach 2 using an array 

class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        vector<int>nums(2001,0);
        for(int i=0;i<arr.size();i++)
        {
            nums[arr[i]+1000]++;
        }
        sort(begin(nums),end(nums));
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]!=0 && nums[i]==nums[i-1])
            {
                return false;
            }
        }
        return true;
    }
};