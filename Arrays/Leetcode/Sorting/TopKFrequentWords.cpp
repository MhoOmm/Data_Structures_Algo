// using vector of <string,int>
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;

        for(string &s:words)
        {
            mp[s]++;
        }

        vector<pair<string,int>>arr;

        for(auto &it:mp)
        {
            string word=it.first;
            int freq=it.second;
            arr.push_back({word,freq});
        }
        auto lambda=[](pair<string,int>p1 , pair<string,int>p2){
            if(p1.second==p2.second)
            {
                return p1.first < p2.first;
            }else{
                return p1.second > p2.second;
            }
        };
        sort(begin(arr),end(arr),lambda);
        vector<string>ans(k);
        int i=0;
        while(i<k)
        {
            ans[i]=(arr[i].first);
            i++;
        }
        return ans;
    }
};