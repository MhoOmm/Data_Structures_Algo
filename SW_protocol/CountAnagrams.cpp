// User function template for C++
class Solution {
  public:
    bool allZero(vector<int>&counter)
    {
        for( int &i:counter)
        {
            if(i!=0)
            {
                return false;
            }
        }
        return true;
    }
    int search(string &pat, string &txt) {
        // code here
        int n=txt.length();
        vector<int>counter(26,0);
        // frequency array
        for(int i=0;i<pat.length();i++)
        {
            char ch=pat[i];
            counter[ch-'a']++;
        }
        
        int i=0;
        int j=0;
        int result=0;
        
        while(j<n)
        {
            counter[txt[j]-'a']--;
            if(j-i+1==pat.length())
            {
                if(allZero(counter)){
                    result++;
                }
                counter[txt[i]-'a']++;
                i++; 
            }
            j++;
        }
        return result;
        
    }
};