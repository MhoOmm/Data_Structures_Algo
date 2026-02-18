class Solution {
public:
    bool isGood(vector<int>&freq,int k)
    {
        for(int i=0;i<3;i++)
        {
            if(freq[i]<k)
            {
                return false;
            }
        }
        return true;
    }
    int takeCharacters(string s, int k) {
        int n = s.length();
        vector<int>freq(3,0);
        for(char &ch:s)
        {
            freq[ch-'a']++;
        }
        for(int i=0;i<3;i++)
        {
            if(freq[i]<k)
            {
                return -1;
            }
        }
        int minLength = n;
        int i = 0;
        int j = 0;
        while(j<n)
        {
            freq[s[j]-'a']--;
            while(freq[s[j]-'a']<k)
            {
                freq[s[i]-'a']++;
                i++;
            }
            if(isGood(freq,k))
            {
                minLength = min(minLength,n-(j-i+1));
            }

            j++;

        }

        return minLength;
    }
};