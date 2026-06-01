class Solution {
public:
    int minimumCost(vector<int>& cost) {
        int n = cost.size();
        if(n==1)
        {
            return cost[0];
        }
        sort(begin(cost),end(cost));

        int price = 0;
        int i=n-1;
        while(i>=0)
        {
            price+=cost[i]; // adding the first item
            if(i-1>=0){
                price+=cost[i-1]; // adding the second item
            }
            i-=3;
        }
        return price;
    }
};