class Solution {
public:
    int numberOfSpecialChars(string word) {
        unordered_set<char>st;
        for(char &c:word)
        {
            st.insert(c);
        }
        int count =0;
        for(char &c:word)
        {
            char small = c+32;
            if(st.count(small))
            {
                count++;
                st.erase(small);
            }
        }

        return count;
    }
};