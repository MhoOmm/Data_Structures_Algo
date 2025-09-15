//recursion +memoization
class Solution {
public:
    int n;
    int solve(int i,int prev,string &s,vector<vector<int>>&t)
    {
        if(i>=n)
        {
            return 0;
        }
        if(t[i][prev] != -1)
            return t[i][prev];

        int flip=INT_MAX;
        int noflip=INT_MAX;

        if(s[i]=='0')
        {
            if(prev==0)
            {
                flip=1+solve(i+1,1,s,t);
                noflip=solve(i+1,0,s,t);
            }else{
                flip=1+solve(i+1,1,s,t);
            }
        }else{
            if(prev==0)
            {
                flip=1+solve(i+1,0,s,t);
                noflip=solve(i+1,1,s,t);
            }else{

                noflip=solve(i+1,1,s,t);
            }
        }

        return t[i][prev]=min(flip,noflip);

    }
    int minFlipsMonoIncr(string s) {
        n=s.length();
        int prev=0;
        vector<vector<int>> t(n+1, vector<int>(2, -1));
        return solve(0,prev,s,t);
        
    }
};

//smart approach

class Solution {
public:
    int minFlipsMonoIncr(string s) {

        int n=s.length();
        int flip=0;
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='0')
            {
                flip=min(count,flip+1);
            }
            else{
                count++;
            }
        }
        return flip;
        
    }
};
