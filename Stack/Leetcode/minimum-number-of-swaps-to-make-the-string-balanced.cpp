class Solution {
public:
    int minSwaps(string s) {
        stack<char> st;
        int imbalance = 0;

        for(char c : s) {
            if(c == '[')
                st.push(c);
            else {
                if(!st.empty())
                    st.pop();
                else
                    imbalance++;
            }
        }

        return (imbalance + 1) / 2;
    }
};
