class Solution {
public:
    int n;
    unordered_map<string,int>mp;
    bool containDupl(string &s1,string&s2){
        vector<int>freq(26,0);

        for(char ch:s1)
        {
            freq[ch-'a']++;
        }
        for(char ch:s2)
        {
            freq[ch-'a']++;
        }

        for(int n:freq)
        {
            if(n>1)
            {
                return true;
            }
        }

        return false;

    }
    int solve(int i,vector<string>& arr,string &prev){
        if(i>=n)return prev.length();

        int take = 0;
        int skip = 0;

        if(mp.find(prev)!=mp.end())
        {
            return mp[prev];
        }

        if(!containDupl(arr[i], prev)){
            prev += arr[i];
            take = solve(i+1,arr,prev);
            prev.erase(prev.size() - arr[i].size());
        }

        skip = solve(i+1,arr,prev);

        return mp[prev]=max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        string prev = "";
        mp.clear();
        n = arr.size();
        return solve(0,arr,prev); 
    }
};