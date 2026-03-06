// Just checking is there is any one coming after there have been zeroes
class Solution {
public:
    bool checkOnesSegment(string s) {
        int n = s.length();
        if(n==1)return s[0]=='1';
        bool flag  = false;
        for(int i=1;i<n;i++){
            if(s[i]=='0' && flag == false)
            {
                flag = true;
            }else if(flag==true && s[i]=='1')
            {
                return false;
            }
        }
        return true;
    }
};