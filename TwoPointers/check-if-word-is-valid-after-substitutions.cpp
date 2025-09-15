class Solution {
public:
    bool isValid(string s) {
        int n= s.length();
        int i =0;
        for(int j =0;j<n;j++)
        {
            s[i]=s[j];
            i++;
            if(i>=3 && s[i-3]=='a'&& s[i-2]=='b' && s[i-1]=='c' ){
                i-=3;
            }
        }
        return i==0?true:false;
    }
};