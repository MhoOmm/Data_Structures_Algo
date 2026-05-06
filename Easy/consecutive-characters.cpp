class Solution {
public:
    int maxPower(string s) {
        int maxCount = INT_MIN;
        int count =0;
        for(int i=0;i<s.length();i++)
        {
            count++;
            if(s[i]!=s[i+1]){
                maxCount = max(maxCount,count);
                count = 0;
            }
        }
        return maxCount;
    }
};