class Solution {
public:
    int findComplement(int n) {
        string binary = "";
        if(n==0)
        {
            return 1;
        }
        while(n>0)
        {
            int r = n%2;
            char ch = '0' + r;
            binary += ch;
            n = n/2;
        }
        reverse(begin(binary),end(binary));
        for(auto &ch:binary)
        {
            if(ch=='0')
            {
                ch = '1';
            }else{
                ch= '0';
            }
        }
        int ans = stoi(binary,nullptr,2);
        
        return ans;  
    }
};


// Optimised way
class Solution {
public:
    int findComplement(int n) {

        int count =0;
        int temp= n;
        while(n>0)
        {
            count++;
            n>>=1;
        }
        long long mask = (1LL << count) - 1;
        return temp^mask;
    }
};
    