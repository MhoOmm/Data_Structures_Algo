// o(nlogn)-TC
// o(n)=SC 

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int>pq;
        for(int i=0;i<n;i++)
        {
            pq.push(piles[i]);
        }
        while(k>0)
        {
            int num=pq.top();
            pq.pop();
            pq.push((num+1)/2);
            k--;
        }
        int sum= 0;
        while(!pq.empty())
        {
            sum+=pq.top();
            pq.pop();
        }

        return sum;
    }
};
