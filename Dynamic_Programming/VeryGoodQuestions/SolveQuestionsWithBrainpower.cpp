// Top Down Approach (O(N^2))
class Solution {
public:
    int n;
    long long t[100001];
    long long solve(int i,vector<vector<int>>& questions)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int cost = questions[i][0];
        long dist = questions[i][1];
        long long take = cost + solve(i+dist+1,questions);
        long long skip = solve(i+1,questions);

        return t[i] = max(take,skip);
    }
    long long mostPoints(vector<vector<int>>& questions) {
        n = questions.size();
        memset(t,-1,sizeof(t));
        return solve(0,questions) ; 
    }
};


// Bottom Up Approach (O(N^2)) (Good Bottom Up) (right to left)

class Solution {
public:
    long long mostPoints(vector<vector<int>>& q) {
        int n = q.size();

        vector<long long >t(200001,0);

        for(int i=n-1;i>=0;i--)
        {
            t[i] = max(q[i][0]+t[i + q[i][1] + 1],t[i+1]);
        }

        return t[0];
        
    }
};