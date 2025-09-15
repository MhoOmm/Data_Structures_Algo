class Solution {
public:
    int minTaps(int n, vector<int>& ranges) {
        vector<int>startarr(n+1,0);
        for(int i=0;i<ranges.size();i++)
        {
            int start=max(0,i-ranges[i]);
            int end=min(n,i+ranges[i]);
            startarr[start]=max(startarr[start],end);
        }

        int taps=0;
        int maxend=0;
        int currend=0;

        for(int i=0;i<=n;i++)
        {
            if(i>maxend)
            {
                return -1;
            }
            if(i>currend)
            {
                taps++;
                currend=maxend;
            }
            maxend=max(maxend,startarr[i]);
        }

        return taps;
    }
};