class Solution {
public:
    bool isOk(string str)
    {
        vector<int>freq(26,0);
        for(int i=0;i<str.length();i++)
        {
            freq[str[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(freq[i]>2)
            {
                return false;
            }
        }
        return true;
    }
    int maximumLengthSubstring(string s) {
        int n = s.length();
        int maxLength = 0;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if(isOk(s.substr(i,j-i+1)))
                {
                    maxLength = max(maxLength,j-i+1);
                }
            }
        }
        return maxLength;
    }
};