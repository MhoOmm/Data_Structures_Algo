// worst case -> O(5*n)
class Solution {
public:
    int waviness(int num){
        int peak=0;
        int valley=0;

        string s = to_string(num);
        if(s.length()<3)
        {
            return 0;
        }
        for(int i=1;i<s.length()-1;i++)
        {
            int prev = s[i-1]-'0';
            int curr = s[i]-'0';
            int next = s[i+1]-'0';
            if(curr>prev && curr>next){
                peak++;
            }
            if(curr<prev && curr<next){
                valley++;
            }
        }
        return peak+valley;
    }
    int totalWaviness(int num1, int num2) {
        int total = 0;
        for(int i=num1;i<=num2;i++)
        {
            total+=waviness(i);
        }
        return total;
    }
};