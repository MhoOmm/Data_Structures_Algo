class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.length();
        stack<char>st;
        for(auto &digit:num)
        {
            while (!st.empty() && k > 0 && st.top() > digit) {
                st.pop();
                k--;
            }
            st.push(digit);
        }
        // k not zero so we have to remove from behind
        while (k > 0 && !st.empty()) {
            st.pop();
            k--;
        }

        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(begin(ans),end(ans));
        int i = 0;
        while (i < ans.size() && ans[i] == '0') {
            i++;
        }

        ans = ans.substr(i);

        return ans.empty() ? "0" : ans;
    }
};