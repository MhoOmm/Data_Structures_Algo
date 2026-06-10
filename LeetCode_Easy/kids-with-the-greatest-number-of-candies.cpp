class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extra) {
        int n = candies.size();
        vector<bool>result(n,false);
        for(int i=0;i<n;i++)
        {
            candies[i] += extra;
            if(*max_element(begin(candies),end(candies)) == candies[i])
            {
                result[i] = true;
                candies[i]-=extra;
            }
        }

        return result;
    }
};