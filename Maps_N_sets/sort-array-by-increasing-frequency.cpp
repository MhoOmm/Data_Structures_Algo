// Comparator Function
class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums)
        {
            mp[num]++;
        }
        auto comparator=[&mp](int &a,int &b){
            if(mp[a]==mp[b]){
                return a>b;
            }else{
                return mp[a]<mp[b];
            }
        };

        sort(begin(nums),end(nums),comparator);
        return nums;
    }
};


// a good trick

class Solution {
public:
    typedef pair<int,int> p;
    vector<int> frequencySort(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int,int>mp;
        for(auto &num:nums)
        {
            mp[num]++;
        }

        priority_queue<p,vector<p>,greater<p>> pq;
        for(auto &it:mp)
        {
            pq.push({it.second,-it.first});
        }

        vector<int>ans;
        while(!pq.empty())
        {
            int iter = pq.top().first;
            int num = -pq.top().second;
            for(int i=0;i<iter;i++)
            {
                ans.push_back(num);
            }
            pq.pop();
        }

        return ans;
    }
};