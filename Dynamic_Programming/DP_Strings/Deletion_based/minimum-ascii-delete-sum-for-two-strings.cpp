class Solution {
public:
    int m,n;
    int t[1001][1001];
    int solve(int i,int j,string&s1,string &s2)
    {
        // base cases
        if(i>=m && j>=n) // both out of bounds
        {
            return 0; // nothing left to be added;
        }
        if(i>=m && j<n) // j left out
        {
            int rem = 0;
            for(int k=j;k<n;k++)
            {
                rem+= (int)s2[k];
            }
            return t[i][j] = rem;
        }

        if(j>=n && i<m) // j left out
        {
            int rem = 0;
            for(int k=i;k<m;k++)
            {
                rem+= (int)s1[k];
            }
            return t[i][j] = rem;
        }

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
        int deli = (int)s1[i] + solve(i+1,j,s1,s2);
        // delete j
        int delj = (int)s2[j] + solve(i,j+1,s1,s2);

        return t[i][j] = min(deli,delj);
    }
    int minimumDeleteSum(string s1, string s2) {
        memset(t,-1,sizeof(t));
        m = s1.length();
        n = s2.length();
        return solve(0,0,s1,s2);
    }
};