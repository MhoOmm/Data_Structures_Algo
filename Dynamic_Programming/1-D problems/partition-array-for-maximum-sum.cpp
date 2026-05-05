// Recurr + memoization
class Solution {
public:
    int t[501];
    int solve(vector<int>& arr, int k,int i){
        if(i>= arr.size())
        {
            return 0;
        }
        if(t[i]!=-1)
        {
            return t[i];
        }
        int result = INT_MIN;
        int currMax = -1;
        for(int j=i;j< arr.size() && (j-i+1)<=k ;j++)
        {
            currMax = max(currMax,arr[j]);
            int sum = currMax*(j-i+1);
            sum = sum + solve(arr,k,j+1);
            result = max(result,sum);
        }
        return t[i] = result;
    }
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        memset(t,-1,sizeof(t));
        return solve(arr,k,0);
    }
};

// bottom up
class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n = arr.size();
        vector<int>t(n+1,0);
        for(int i=1;i<=n;i++)
        {
            int currMax = 0;
            for(int j=1;j<=k && j<=i;j++)
            {
                currMax = max(currMax,arr[i-j]);
                int sum = currMax*j + t[i-j];
                t[i] = max(t[i],sum);
            }
        }
        return t[n];
    }
};