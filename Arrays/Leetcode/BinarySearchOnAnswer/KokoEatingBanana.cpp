// correct but giving wrong answer
class Solution {
public:
    int caneat(long long mid, const vector<int>& piles) {
        int h = 0;
        for (int pile : piles) {
            h += (pile + mid - 1) / mid;
        }
        return h;
    }

    int minEatingSpeed(vector<int>& piles, int h) {
        long long start = 1;
        long long endi = *max_element(piles.begin(), piles.end());
        long long result = -1;

        while (start <= endi) {
            long long mid = start + (endi - start) / 2;
            if (caneat(mid, piles) <= h) {
                result = mid;
                endi = mid - 1;
            } else {
                start = mid + 1;
            }
        }

        return (int)result;
    }
};