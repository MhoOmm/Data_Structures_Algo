class Solution {
public:
    int M = 1e9 + 7;
    int countPermutations(vector<int>& comp) {

        int n = comp.size();
        long long  result = 1;
        for(int i=1;i<n;i++)
        {
            if(comp[i]<=comp[0])
            {
                return 0;
            }
            result = (result*i)%M;
        }
        return result;
        
    }
};