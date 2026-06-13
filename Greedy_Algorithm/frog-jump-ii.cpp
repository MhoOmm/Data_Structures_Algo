class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        // alternatively max stone diff
        int diff = stones[1] - stones[0]; //(min diff to start with)
         
        for(int i=2;i<n;i++)
        {
            diff = max(diff,stones[i]-stones[i-2]);
        }
        return diff;
    }
};