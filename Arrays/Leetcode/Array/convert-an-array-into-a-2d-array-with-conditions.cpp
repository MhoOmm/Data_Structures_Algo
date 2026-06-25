class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int,int>mp; // nums[i]->freq;
        for(auto &num:nums)
        {
            mp[num]++;
        }
        vector<vector<int>>ans;
        while(!mp.empty())
        {
            vector<int>temp;
            vector<int> erase;
            for(auto &it:mp)
            {
                int num = it.first;
                temp.push_back(num);
                mp[num]--;
                if(mp[num]==0)
                {
                    erase.push_back(num);
                }
            }
            for(int x : erase){
                mp.erase(x);
            }
            ans.push_back(temp);
        }

        return ans;
    }
};