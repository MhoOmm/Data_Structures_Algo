class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long ans =0;
        int hired= 0;
        priority_queue<int,vector<int>,greater<int>>pq1;
        priority_queue<int,vector<int>,greater<int>>pq2;

        int i=0;
        int j=n-1;
        while(hired<k)
        {

            while(pq1.size()<candidates && i<=j)
            {
                pq1.push(costs[i]);
                i++;
            }
            while(pq2.size()<candidates && j>=i)
            {
                pq2.push(costs[j]);
                j--;
            }

            int min_pq1=pq1.empty()?INT_MAX:pq1.top();
            int min_pq2=pq2.empty()?INT_MAX:pq2.top();
            if(min_pq1<=min_pq2)
            {
                ans+=min_pq1;
                hired++;
                pq1.pop();
            }
            else{
                ans+=min_pq2;
                hired++;
                pq2.pop();
            }

        }
        return ans;
    }
};