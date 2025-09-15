// good approach
class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n=piles.size();
        int result=0;
        sort(begin(piles),end(piles));
        for(int i=n/3;i<n;i+=2)
        {
            result+=piles[i];
        }
        return result;
    }
};

// two pointers

class Solution {
public:
    int maxCoins(vector<int>& piles) {
        int n = piles.size();
        sort(begin(piles),end(piles));
        int b = 0;
        int m = n - 2;
        int result=0;
        while(b<m)
        {
            result+=piles[m];
            b++;
            m-=2;
        }
        return result; 
    }
};