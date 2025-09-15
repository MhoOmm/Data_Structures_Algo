class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        int n=costs.size();
        int count=0;
        sort(begin(costs),end(costs));
        for(int i=0;i<n;i++)
        {
           if(coins>=costs[i])
           {
                coins-=costs[i];
                count++;
           }
           if(coins==0){
                break;
           }
        }
        return count;
    }
};