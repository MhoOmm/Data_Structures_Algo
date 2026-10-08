class Solution {
public:
    string removeOuterParentheses(string s) {
        int n = s.length();
        int count = 0;
        string result;
        for(auto &ch:s)
        {
            if( ch=='(')
            {
                if(count!=0)
                {
                    result.push_back(ch);
                }
                count++;
            }
            else{
                count--;
                if(count!=0)
                {
                    result.push_back(ch);
                }
            }
        }
        return result;
    }
};