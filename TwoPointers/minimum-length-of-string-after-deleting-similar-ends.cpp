class Solution {
public:
    int minimumLength(string s) {
        int n = s.length();
        if(n==1)
        {
            return 1;
        }
        int i = 0;
        int j = n-1;
        while(i<j && s[i]==s[j])
        {
            char ch = s[j];
            // kitna bada prefix le sakta hoon
            while(i<j && s[i]==ch)
            {
                i++;
            }
            // kitna bada suffix khoj sakta hoon
            while(j>=i && s[j]==ch){
                j--;
            }
        }

        return j-i+1;
    }
};