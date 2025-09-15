class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.length();
        vector<int> arr(n, 0);
        
        // Apply difference array approach
        for (auto& q : shifts) {
            int start = q[0], end = q[1], x = q[2];
            if(x==0)
            {
                x=-1;
            }
            else if(x==1)
            {
                x=1;
            }
            arr[start] += x;
            if (end + 1 < n) {
                arr[end + 1] -= x;
            }
        }
        int val=0;
        for (int i = 0; i < n; ++i) {
            arr[i] = arr[i]+val;
            val=arr[i];
        }
        string ans = s;
        for (int i = 0; i < n; ++i) {
            int shift = arr[i] % 26;
            int newChar = ((s[i] - 'a') + shift) % 26;
            if (newChar < 0) newChar += 26;  // Handle negative shift
            ans[i] = 'a' + newChar;
        }

        return ans;
    }
};