// giving tle
class Solution {
public:
    int countvowels(string &str)
    {
        int count=0;
        for(char &ch:str){
            if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                count++;
            }
        }
        return count;
    }
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        int cv=0;
        int result=INT_MIN;
        while(j<n)
        {
            if(j-i+1==k)
            {
                string str=s.substr(i,k);
                cv=countvowels(str);
                result=max(result,cv);
                i++;
            }
            j++;
        }
        return result;
    }
};

// optimised

class Solution {
public:
    bool isvowel(char &ch)
    {
        if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u')
            {
                return true;
            }
        return false;
    }
    int maxVowels(string s, int k) {
        int n=s.length();
        int i=0,j=0;
        int count=0;
        int maxv=0;
        while(j<n)
        {
            if(isvowel(s[j]))
            {
                count++;
            }
            if(j-i+1==k)
            {
                maxv=max(maxv,count);
                if(isvowel(s[i]))
                {
                    count--;
                }
                i++;
            }
            j++;
        }
        return maxv;
    }
};