class Solution {
public:
    typedef long long ll ;
    vector<long long> findMaxSum(vector<int>& nums1, vector<int>& nums2, int k) {
        int n= nums1.size();

        vector<vector<int>>arr(n);

        for(int i=0;i<n;i++)
        {
            arr[i]={nums1[i],i,nums2[i]};
        }

        sort(begin(arr),end(arr));

        vector<ll>result(n,0);

        priority_queue<int,vector<int>,greater<int>>pq;

        ll sum= 0;

        for(int i=0;i<n;i++)
        {
            if(i>0 && arr[i-1][0]==arr[i][0])
            {
                long long  ans = result[arr[i-1][1]];
                result[arr[i][1]]=ans;
            }
            else{
                result[arr[i][1]]=sum;
            }

            pq.push(arr[i][2]);
            sum+=arr[i][2];
            if (pq.size()>k)
            {
                sum-=pq.top();
                pq.pop();
            }
        }
        return result;
    }
};