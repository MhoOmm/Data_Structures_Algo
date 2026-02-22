class Solution {
public:
    int binaryGap(int n) {
        string binary;
        while(n>0)
        {
            int rem = n%2;
            binary += (rem + '0');
            n=n/2;
        }
        reverse(binary.begin(),binary.end());

        int distance =0;
        int last = -1;

        for(int i=0;i<binary.length();i++)
        {
            if(binary[i]=='1')
            {
                if(last!=-1)
                {
                    distance = max(distance, i-last);
                }
                last = i;
            }
        }

        return distance;
    }
};