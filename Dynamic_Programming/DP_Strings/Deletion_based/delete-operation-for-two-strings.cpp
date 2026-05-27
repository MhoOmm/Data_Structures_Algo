class Solution {
public:
    int m,n;
    int t[501][501];
    int solve(int i,int j,string&s1,string &s2)
    {
        // base cases
        if(i>=m && j>=n) // both out of bounds
        {
            return 0; // nothing left to be added;
        }
        if(i>=m)
            return n-j;

        if(j>=n)
            return m-i;
            
        if(t[i][j]!=-1)
        {
            return t[i][j];
        }
        // if both equal move ahead
        if(s1[i]==s2[j])
        {
            return t[i][j] = solve(i+1,j+1,s1,s2);
        }
        // delete i
        int deli = 1 + solve(i+1,j,s1,s2);
        // delete j
        int delj = 1 + solve(i,j+1,s1,s2);

        return t[i][j] = min(deli,delj);
    }
    int minDistance(string word1, string word2) {
        memset(t,-1,sizeof(t));
        m = word1.length();
        n = word2.length();
        return solve(0,0,word1,word2); 
    }
};