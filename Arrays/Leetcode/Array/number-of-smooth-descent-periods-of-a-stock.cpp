class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {

        long long curr = 1;
        long long total = 1;
        int n = prices.size();
        for(int i = 1; i < n; i++) {
            if(prices[i - 1] - 1 == prices[i]) {
                curr++;         
            } else {
                curr = 1;     
            }
            total += curr;
        }

        return total;
        
    }
};