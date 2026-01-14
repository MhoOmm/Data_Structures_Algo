class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st(arr.begin(), arr.end());

        for (int i = 0; i < n; i++) {
            int num = arr[i] * 2;

            if (arr[i] == 0) {
                if (count(arr.begin(), arr.end(), 0) > 1)
                    return true;
            } 
            else if (st.find(num) != st.end()) {
                return true;
            }
        }
        return false;
    }
};
