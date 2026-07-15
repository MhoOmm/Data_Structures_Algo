// top-down approach - giving tle - O(mn^2)
class Solution {
public:
    int n,m;
    vector<vector<long long>>dp;
    long long solve(int i,int j,vector<vector<int>>&points)
    {
        if(i<0 || j<0 || j>=n || i>=m)
        {
            return LLONG_MIN; // very small value;
        }
        if(i==m-1)
        {
            return points[i][j];
        }
        if(dp[i][j]!=LLONG_MIN)
        {
            return dp[i][j];
        }
        long long ans = LLONG_MIN;
        for(int k=0;k<n;k++)
        {
            long long nextEle = solve(i+1,k,points);
            if(nextEle != LLONG_MIN){
                ans = max(ans,points[i][j] + nextEle - abs(j-k)); 
            }
        }
        return dp[i][j] =  ans;
    }
    long long maxPoints(vector<vector<int>>& points) {
        m = points.size();
        n = points[0].size();
        long long result = LLONG_MIN;
        dp.assign(m, vector<long long>(n, LLONG_MIN));
        for(int j=0;j<n;j++)
        {
            result = max(result,solve(0,j,points));
        }
        return result;
    }
};

// tc: o(m*n*n)

class Solution {
    public:
        typedef long long ll;
        long long maxPoints(vector<vector<int>>& points) {
    
            int m=points.size();
            int n=points[0].size();
    
            vector<long long>prev(n);
            int score=0;
            for(int col=0;col<n;col++)
            {
                prev[col] = points[0][col];
            }
    
            for(int row=1;row<m;row++)
            {
                vector<long long>curr(n);
                for(int col=0;col<n;col++)
                {
                    for(int k=0;k<n;k++)
                    {
                        curr[col]=max(curr[col],(points[row][col]+prev[k]-abs(col-k)));
                    }
                }
                prev=curr;
            }
    
            return *max_element(begin(prev),end(prev));
            
        }
    };

//better approach
class Solution {
    public:
        typedef long long ll;
        ll maxPoints(vector<vector<int>>& points) {
            int m = points.size(), n = points[0].size();
            vector<ll> prev(n);
            int score = 0;
            
            for(int col = 0; col < n; col++) {
                prev[col] = points[0][col];
            }
            
            for(int i = 1; i<m; i++) {
                vector<ll> curr(n);
                auto left = curr, right = curr;
                left[0] = prev[0];
                for(int j = 1; j<n; j++) {
                    left[j] = max(prev[j], left[j-1]-1);             
                }
                
                //Fill right
                right[n-1] = prev[n-1];
                for(int j = n-2; j >= 0; j--) {
                    right[j] = max(prev[j], right[j+1]-1); 
                }
                
                for(int j = 0; j<n; j++)
                    curr[j] = points[i][j] + max(left[j], right[j]); 
                
                prev = curr;
            }
            return *max_element(prev.begin(), prev.end());
        }
    };
