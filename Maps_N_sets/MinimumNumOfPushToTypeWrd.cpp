// part 1
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        if(n<8)
        {
            return n;
        }
        unordered_map<int,int>mp;
        int count = 2;
        int result = 0;

        for(int i=0;i<n;i++)
        {
            if(count>9)
            {
                count = 2;
            }

            mp[count]++;
            result += mp[count];
            count++;
        }

        return result;
    }
};


// part 2
class Solution {
public:
    int minimumPushes(string word) {
        int n = word.length();
        vector<int>mp(26,0);
        for(char &ch:word)
        {
            mp[ch-'a']++;
        }

        sort(begin(mp),end(mp),greater<int>());
        int ans = 0;
        for(int i=0;i<26;i++)
        {
            ans+=mp[i]*((i/8)+1);
        }

        return ans;
    }
};