// Brute force approach
class Solution {
public:
    int bitwiseComplement(int n) {

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

// Smart approach

class Solution {
public:
    int bitwiseComplement(int n) {
        int count =0;
        int ans =0;
        if(n==0)
        {
            return 1;
        }
        while(n>0)
        {
            int r = n%2;
            ans += (pow(2,count) * !r);
            n = n/2;
            count++;
        }

        return ans;
        
    }
};