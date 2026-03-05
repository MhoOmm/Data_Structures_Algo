class Solution {
public:
    int minOperations(string s) {
        int countzero = 0;
        int countone = 0;
        int n = s.length();

        // starts with one
        string temp = s;
        if(s[0]!='1')
        {
            s[0] = '1';
            countone++;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                countone++;
                s[i] = s[i]=='1'?'0':'1';
            }
        }
        // starts with zero
        s = temp;
        if(s[0]!='0')
        {
            s[0] = '0';
            countzero++;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                countzero++;
                s[i] = s[i]=='1'?'0':'1';
            }
        }

        return min(countzero,countone);
    }
};


// Slightly better (jahan jahan hamein startsone mein edit karna hoga udhar starts
// startszero mein update nhi karna hai toh )
// countzero = n-countone;

class Solution {
public:
    int minOperations(string s) {
        int countzero = 0;
        int countone = 0;
        int n = s.length();

        // starts with one
        string temp = s;
        if(s[0]!='1')
        {
            s[0] = '1';
            countone++;
        }
        for(int i=1;i<n;i++)
        {
            if(s[i-1]==s[i])
            {
                countone++;
                s[i] = s[i]=='1'?'0':'1';
            }
        }
        countzero = n-countone;
        return min(countzero,countone);
    }
};