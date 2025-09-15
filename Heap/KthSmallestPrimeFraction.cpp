
// o(n^2+nlogk)
class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        priority_queue<vector<double>>pq;

        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                double div=(double)arr[i]/arr[j];
                pq.push(vector<double>{div, (double)arr[i], (double)arr[j]});

                if(pq.size()>k)
                {
                    pq.pop();
                }
            }
        }
        vector<int>result(2);
        auto it=pq.top();
        result[0]=it[1];
        result[1]=it[2];

        return result;
    }
};