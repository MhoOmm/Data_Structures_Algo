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


// another solution without memoization coz very small constraints
// O(2^n)
class Solution {
public:
    bool isUnique(string s1)
    {
        vector<int>freq(26,0);
        for(auto &ch:s1)
        {
            freq[ch-'a']++;
        }  
        for(int i=0;i<26;i++)
        {
            if(freq[i]>1)
            {
                return false;
            }
        }

        return true;
    }
    int solve(int i,vector<string>&arr, string word)
    {
        if(i>=arr.size())
        {
            return 0;
        }
        int take = 0;
        if(isUnique(word+arr[i]))
        {
            string temp = word;
            word = word + arr[i];
            take = arr[i].length() + solve(i+1,arr,word);
            word = temp;
        }
        int skip = solve(i+1,arr, word);

        return max(take,skip);
    }
    int maxLength(vector<string>& arr) {
        return solve(0,arr,"");
    }
};