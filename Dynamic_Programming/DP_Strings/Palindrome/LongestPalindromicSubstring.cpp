
// recursion and memoization
class Solution {
    public:
        int t[1001][1001];
    
        bool recur(string &s, int i, int j) {
            if(i > j) return true;
    
            if(t[i][j] != -1)
                return t[i][j];
    
            if(s[i] == s[j])
                return t[i][j] = recur(s, i+1, j-1);
            else
                return t[i][j] = false;
        }
    
        string longestPalindrome(string s) {
            int n = s.length();
            memset(t, -1, sizeof(t));
    
            int maxl = 0;
            int start = 0;
    
            for(int i = 0; i < n; i++) {
                for(int j = i; j < n; j++) {
                    if(recur(s, i, j)) {
                        if(j - i + 1 > maxl) {
                            maxl = j - i + 1;
                            start = i;
                        }
                    }
                }
            }
            return s.substr(start, maxl);
        }
    };


//bottom up approach


class Solution {
    public:
        string longestPalindrome(string s) {
            int n = s.length();
            vector<vector<bool>> t(n, vector<bool>(n, false));
    
            int maxl = 1;
            int start = 0;
    
            for (int L = 1; L <= n; L++) {
                for (int i = 0; (i + L - 1) < n; i++) {
                    int j = i + L - 1;
    
                    if (i == j) { // 1-length substring
                        t[i][j] = true;
                    }
                    else if (i + 1 == j) { // 2-length substring
                        t[i][j] = (s[i] == s[j]);
                    }
                    else {
                        t[i][j] = (s[i] == s[j] && t[i + 1][j - 1]);
                    }
    
                    if (t[i][j] && L > maxl) {
                        maxl = L;
                        start = i;
                    }
                }
            }
    
            return s.substr(start, maxl);
        }
    };