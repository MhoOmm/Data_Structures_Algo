class Solution {
public:
    int countOdds(int low, int high) {
        int even1 = low%2;
        int even2 = high%2;
        if(low==high)
        {
            return low%2!=0;
        }
        if(even1==0 && even2==0){
            return ( high-low)/2;
        }else if(even1!=0 && even2!=0){
            return (high-low-1)/2 +2;
        }

        return (high-low)/2 +1;
    }
};