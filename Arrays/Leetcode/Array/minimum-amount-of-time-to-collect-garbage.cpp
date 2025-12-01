class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {

        int n = garbage.size();
        int total = 0;

        int m =0;
        int g =0;
        int p =0;

        for(int i =0;i<n;i++)
        {
            for(int j=0;j<garbage[i].length();j++)
            {
                if(garbage[i][j]=='M')
                {
                    m=i;
                }else if(garbage[i][j]=='G')
                {
                    g=i;
                }else {
                    p = i;
                }

                total++;
            }
        }
        for(int i = 1; i < travel.size(); i++) {
            travel[i] += travel[i-1];
        }

        total += m>0?travel[m-1]:0;
        total += g>0?travel[g-1]:0;
        total += p>0?travel[p-1]:0;

        return total;

    }
};