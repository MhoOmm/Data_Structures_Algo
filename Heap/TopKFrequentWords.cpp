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