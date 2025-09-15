class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n=shifts.size();
        vector<long long > suffixSum(n);
        long long sum = 0;

        for (int i = n - 1; i >= 0; --i) {
            sum += shifts[i];
            suffixSum[i] = sum%26;
        }

        for(int i=0;i<s.length();i++)
        {
            int val=s[i]-'a';
            val = (val + suffixSum[i]) % 26;
            s[i]=val+'a';
        }
        return s;
    
    }
};