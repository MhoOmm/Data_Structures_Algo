class Solution {
public:
    typedef pair<int,string> pp;
    struct lambda{
        bool operator()(pp &p1 , pp &p2)
        {
            if(p1.first==p2.first)
            {
                return p1.second > p2.second;
            }else{
                return p1.first < p2.first;
            }
        }
    };
    vector<string> topKFrequent(vector<string>& words, int k) {
        int n=words.size();
        unordered_map<string,int>mp;

        for(string &s:words)
        {
            mp[s]++;
        }

        priority_queue<pp,vector<pp>,lambda>pq;

        for(auto &it:mp)
        {
            string str=it.first;
            int freq=it.second;
            pq.push({freq,str});
        }
        vector<string>ans;
        while(k>0)
        {
            string st = pq.top().second;
            pq.pop();
            ans.push_back(st);
            k--;
        }

        return ans;
    }
};