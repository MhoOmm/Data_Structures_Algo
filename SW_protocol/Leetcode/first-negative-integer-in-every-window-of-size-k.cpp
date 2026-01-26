// Brute Force Method - O(n*k)
class Solution {
  public:
    vector<int> firstNegInt(vector<int>& arr, int k) {
        // write code here
        int n = arr.size();
        
        vector<int>result;
        for(int i =0;i<=n-k;i++)
        {
            int j = i+k-1;
            int firstn = 0;
            for(int m = i;m<=j;m++)
            {
                if(arr[m]<0)
                {
                    firstn = arr[m];
                    break;
                }
            }
            result.push_back(firstn);
        }
        
        return result;
    }
};

// optimised approach
