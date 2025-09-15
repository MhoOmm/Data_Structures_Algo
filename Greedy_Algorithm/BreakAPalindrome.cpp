class Solution {
public:
    string breakPalindrome(string palin) {
        int n =palin.length();
        if(n==1)//always a palindrome
        {
           return ""; 
        }
        for(int i=0;i<n/2;i++)
        {
            if(palin[i]!='a')
            {
                palin[i]='a';//a se chaneg kardunga aur even wlae bhi ismein aa gaye
                return palin;
            }
        }
        // agar odd hai to
        // middle element chaneg kardunga
        palin[n-1]='b';

        return palin;

    }
};