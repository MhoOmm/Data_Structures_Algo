class Solution {
  public:
    int maxSubarraySum(vector<int>& arr, int k) {
        // code here
        int n  = arr.size();
        int i =0;
        int j =0;
        int sum =0;
        int maxSum = INT_MIN ;
        
        while(j<n)
        {
            sum+=arr[j];
            while(j-i+1 > k)
            {
                sum-=arr[i];
                i++;
            }
            
            if(j-i+1 == k)
            {
                maxSum = max(maxSum,sum);
            }
            j++;
        }
        
        return maxSum;
    }
};