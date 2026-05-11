//recursion +memoization
class Solution {
public:
    vector<vector<int>>t;
    int solve(int i,int prev,string &s)
    {
        if(i>=s.length())
        {
            return 0;
        }
        if(t[i][prev]!=-1)
        {
            return t[i][prev];
        }
        int flip = INT_MAX;
        int noFlip = INT_MAX;
        if(s[i]=='0')
        {
            if(prev==0)
            {
                noFlip = solve(i+1,0,s);
                flip =1+solve(i+1,1,s); 
            }else{
                flip =1+solve(i+1,1,s);
            }
        }else{
            if(prev==1)
            {
                noFlip = solve(i+1,1,s);
            }else{
                flip = 1 + solve(i+1,0,s); 
                noFlip = solve(i+1,1,s); 
            }
        }

        return t[i][prev] = min(flip,noFlip);
    }
    int minFlipsMonoIncr(string s) {
        int n = s.length();
        t.assign(n,vector<int>(2,-1));
        return solve(0,0,s);
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
