class Solution {
public:
    typedef pair<int, char> pp;

    string reorganizeString(string s) {
        int n = s.length();
        unordered_map<char, int> mp;
        for (char &ch : s) {
            mp[ch]++;
        }

        priority_queue<pp> pq;
        for (auto &it : mp) {
            if (it.second > (n + 1) / 2) {
                return ""; 
            }
            pq.push({it.second, it.first});
        }

        string ans = "";
        while (pq.size() > 1) {
            auto [f1, c1] = pq.top(); pq.pop();
            auto [f2, c2] = pq.top(); pq.pop();

            ans += c1;
            ans += c2;

            if (--f1 > 0) pq.push({f1, c1});
            if (--f2 > 0) pq.push({f2, c2});
        }
        if (!pq.empty()) {
            ans += pq.top().second;
        }

        return ans;
    }
};
