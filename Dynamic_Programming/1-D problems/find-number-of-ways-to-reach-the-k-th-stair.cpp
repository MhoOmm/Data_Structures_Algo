class Solution {
public:
    unordered_map<string,int>mp;
    int solve(int i,int k,bool canBack,int jump)
    {
        // edge
        if(i>k+1)
        {
            return 0;
        }
        // base case
        int ans = 0;
        if(i==k)
        {
            ans+=1; // we dont stop exploring
        }
        string key = to_string(i)+"_"+to_string(jump)+"_"+to_string(canBack);
        if(mp.find(key)!=mp.end())
        {
            return mp[key];
        }
        int backStep =  0;
        if(canBack)
        {
            backStep = solve(i-1,k,false,jump);
        }
        int jumpStep = solve(i+(1 << jump),k,true,jump+1) ;

        ans += backStep + jumpStep;
        return mp[key] = ans;
    }
    int waysToReachStair(int k) {
        return solve(1,k,true,0);
    }
};