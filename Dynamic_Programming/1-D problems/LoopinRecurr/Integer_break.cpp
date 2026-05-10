// backward pass (n->1)
class Solution {
public:
    int t[59];
    int solve(int n)
    {
        if(n==1)
        {
            return 1;
        }
        if(t[n]!=-1)
        {
            return t[n];
        }
        int result=INT_MIN;
        for(int i=1;i<n;i++)
        {  
            result=max({result,i*(n-i),i*solve(n-i)});
        }
        return t[n]=result;
    }
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(n);
    }
};

// forward pass solution (0->n)

class Solution {
public:
    int t[60];
    int solve(int sum,int n)
    {
        if(sum==n)
        {
            return 1;
        }
        if(sum>n)
        {
            return 0;
        }
        if(t[sum]!=-1)
        {
            return t[sum];
        }
        int ans = INT_MIN;
        for(int i=1;i<n;i++)
        {
            int child = solve(sum+i,n);
            if(child>0)
            {
                ans = max(ans,i*child);
            }
        }
        return t[sum] = ans;
    }
    int integerBreak(int n) {
        memset(t,-1,sizeof(t));
        return solve(0,n);
    }
};
