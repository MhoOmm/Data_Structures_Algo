// O(n^2) solution
class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        for(int i=0;i<n+1;i++)
        {
            result[i] = __builtin_popcount(i);
        }

        return result;
    }
};

// Optimal Solution O(n)
// every even number has the same number of one bits as its half has 
// every odd number has +1 of what its half has

class Solution {
public:
    vector<int> countBits(int n) {
        vector<int>result(n+1);
        result[0] = 0;
        for(int i=1;i<=n;i++)
        {
            if(i%2==0)
            {
                result[i] = result[i/2]  ;
            }else{
                result[i] = result[i/2] + 1 ;
            }
        }

        return result;
    }
};