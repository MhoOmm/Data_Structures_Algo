class Solution {
public:
    int countCommas(int n) {
        if(n<1000)
        {
            return 0;
        }
        int maxCount = 0;
        for(int i=1000;i<=n;i++)
        {
            maxCount += 1;
        }
        return maxCount;
    }
};