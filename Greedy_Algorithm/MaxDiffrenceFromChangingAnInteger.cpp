class Solution {
public:
    int maxDiff(int num) {
        vector<int>maxvec;
        

        while(num>0)
        {
            maxvec.push_back(num % 10);
            num = num / 10;
        }
        reverse(begin(maxvec),end(maxvec));
        vector<int>minvec(begin(maxvec),end(maxvec));

        int first_max=0;
        for(int &d:maxvec)
        {
            if(d!=9)
            {
               first_max=d; 
               break;
            }
        }
        int maxnum=0;
        for(int i=0;i<maxvec.size();i++)
        {
            if(maxvec[i]==first_max)
            {
                maxvec[i]=9;
            }
            maxnum = maxnum*10 + maxvec[i];
        }



        int first_min=0;
        int minnum=0;
        if(minvec[0]!=1)
        {
          first_min=minvec[0];
          for(int &d:minvec)
          {
            if(d==first_min)
            {
                d=1;
            }
            minnum = minnum*10 + d;
          }

        }
        else {
            
            for (int i = 1; i < minvec.size(); i++) {
                if (minvec[i] != 0 && minvec[i] != 1) {
                    first_min = minvec[i];
                    break;
                }
            }

            for (int i = 0; i < minvec.size(); i++) {
                if (minvec[i] == first_min) {
                    minvec[i] = 0;
                }
                minnum = minnum * 10 + minvec[i];
            }
        }
        return maxnum-minnum;
    }

};