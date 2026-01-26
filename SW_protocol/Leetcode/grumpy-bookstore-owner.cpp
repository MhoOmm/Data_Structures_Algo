// Slow Solution - O(n*k)
class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int k) {
        int n= cust.size();
        int nonGsum = 0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                nonGsum += cust[i];
            }
        }

        int maxSum =0;
        for(int i =0;i<= n-k;i++){
            int j = i+k-1;
            int oneSum =0;
            for(int st = i;st<=j;st++ )
            {
                if(grumpy[st]==1)
                {
                    oneSum  += cust[st];
                }
            }
            int newSum = nonGsum + oneSum;
            maxSum = max(maxSum,newSum);
        }

        return maxSum;
    }
};

// O(N) solution

class Solution {
public:
    int maxSatisfied(vector<int>& cust, vector<int>& grumpy, int k) {
        int n= cust.size();
        int nonGsum = 0;
        for(int i=0;i<n;i++)
        {
            if(grumpy[i]==0)
            {
                nonGsum += cust[i];
            }
        }
        int extra = 0;
        int maxExtra = 0;
        for(int i =0;i<n;i++)
        {
           if(grumpy[i] == 1)
           {
            extra +=  cust[i];
           }
           if(i>=k && grumpy[i-k] == 1)
           {
            extra -= cust[i-k];
           }

           maxExtra = max(maxExtra,extra);
        }

        return nonGsum + maxExtra;
    }
};