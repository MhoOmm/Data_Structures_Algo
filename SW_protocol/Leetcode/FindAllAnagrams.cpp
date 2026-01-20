class Solution {
public:
    bool allzero(vector<int>&counter)
    {
        for(int &it:counter)
        {
            if(it!=0){
                return false;
            }
        }
        return true;
    }
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans;
        vector<int>counter(26,0);
        int n=s.length();
        for(int i=0;i<p.length();i++)
        {
            char ch=p[i];
            counter[ch-'a']++;
        }
        int i=0,j=0;
        while(j<n)
        {
            counter[s[j]-'a']--;
            if(p.length()==j-i+1)
            {
                if(allzero(counter))
                {
                    ans.push_back(i);
                }
                counter[s[i]-'a']++;
                i++;
            }
            j++;
        }
        return ans;
    }
};