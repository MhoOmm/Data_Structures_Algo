class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = 0;
        int curr = 0;
        string ans = "";
        while(j<n)
        {
            if(s[j]=='1')
            {
                curr++;
            }
            while(curr>k)
            {
                if(s[i]=='1')
                {
                    curr--;
                }
                i++;
            }
            while (i < j && s[i] == '0')
            {
                i++;
            }
            if(curr==k){
                string temp = s.substr(i,j-i+1);
                int len = j-i+1;
                // no answer till now | answer shorter | lexicographicaly smaller
                if( ans.empty() || len < ans.length() || (len == ans.length() && temp < ans))
                {
                    ans = temp;
                }
            }
            j++;
        }
        return ans;
    }
};