// Top Down Approach (O(N^2))
class Solution {
public:
    int n;
    long long t[100001];
    long long solve(int i,vector<vector<int>>& qn)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        // take
        long long take = qn[i][0] + solve(i+qn[i][1]+1,qn);
        // skip
        long long skip = solve(i+1,qn);

        return t[i] = max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(t,-1,sizeof(t));
        return solve(0,questions);
    }
};

// Bottom Up Approach (O(N^2)) (Good Bottom Up) (right to left)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& qn) {
        int n = qn.size();
        vector<long long>t(n+1,0);
        for(int i=n-1;i>=0;i--)
        {
            long long add = (i+qn[i][1]+1)<n?t[i+qn[i][1]+1]:0;
            // take
            long long take = qn[i][0]+add;
            // skip
            long long skip = t[i+1];
            t[i] = max(take,skip);
        }

        return t[0];
    }
};