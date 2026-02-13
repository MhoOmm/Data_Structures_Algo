// TLE solution O(n^2)
class Solution {
public: 
    bool isGood(vector<int>freq)
    {
        int com =0;
        for(int i=0;i<3;i++)
        {
            if (freq[i] > 0)
            {
                if (com == 0){
                    com = freq[i];
                } 
                else if (freq[i] != com){
                    return false;
                }
            }
        }
    
        return true;
    }
    int longestBalanced(string s) {
        int n = s.length();
        int count=0;
        for(int i=0;i<n;i++)
        {
            vector<int>freq(3,0);
            for(int j=i;j<n;j++)
            {
                freq[s[j]-'a']++;
                if(isGood(freq))
                {
                    count= max(count,j-i+1);
                }   
            }
        }

        return count;
    }
};