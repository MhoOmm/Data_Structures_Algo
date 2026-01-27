class Solution {
public:
    int strStr(string haystack, string needle) {
        int n = haystack.length();
        int m  = needle.length();
        if(m>n)return -1;
        int result = -1;
        for(int i=0;i<n;i++)
        {
            if(haystack.substr(i,m) == needle)
            {
                result = i;
                break;
            }
        }
        return result;

    }
};