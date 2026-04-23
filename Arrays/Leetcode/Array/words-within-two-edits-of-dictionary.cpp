// brute force O(n^3)
class Solution {
public:
    bool canChange(string s1,string s2)
    {
        if(s1.length()!=s2.length())
        {
            return false;
        }

        int count =0;
        int n = s1.length();
        for(int i=0;i<n;i++)
        {
            if(s1[i]!=s2[i])
            {
                count++;
            }
            if(count>2)
            {
                return false;
            }
        }

        return true;
    }
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dict) {
        int n = queries.size();
        int m = dict.size();
        vector<string>ans;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(canChange(queries[i],dict[j]))
                {
                    ans.push_back(queries[i]);
                    break;
                }
            }
        }

        return ans;
    }
};


// optimised