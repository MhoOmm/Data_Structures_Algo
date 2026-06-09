class Solution {
public:
    bool judgeCircle(string moves) {
        int sumx =0;
        int sumy =0;
        for(auto &ch:moves)
        {
            if(ch=='U')
            {
                sumy+=1;
            }
            else if(ch=='D')
            {
                sumy-=1;
            }
            else if(ch=='R')
            {
                sumx+=1;
            }
            else if(ch=='L')
            {
                sumx-=1;
            }
        }

        return sumx==0 && sumy==0;
    }
};