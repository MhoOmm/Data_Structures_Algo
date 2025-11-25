// TC - O(N)
// SC - O(N)
class Solution {
public:
    int maxDepth(string s) {

        int n = s.length();
        stack<char>st;

        int count =0;
        int result = 0;

        for(auto &ch:s)
        {
            if(ch == '(')
            {
                st.push(ch);
                count++;
                result = max(result,count);
            }else if(ch == ')'){
                st.pop();
                count--;
            }else{
                continue;
            }
        }

        return result;
    }
};


// O(1) space
class Solution {
public:
    int maxDepth(string s) {

        int n = s.length();

        int result =0;
        int count = 0;

        for(auto &ch:s)
        {
            if(ch=='(')
            {
               count++;
               result = max(result,count);
            }else if(ch == ')'){
                count--;
            }else{
                continue;
            }
        }

        return result;
        
    }
};