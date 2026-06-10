class Solution {
public:
    bool validcode(const string& str) {
        if (str.empty()) return false;

        for (char ch : str) {
            if (!isalnum((unsigned char)ch) && ch != '_') {
                return false;
            }
        }
        return true;
    }

    vector<string> validateCoupons(vector<string>& code,vector<string>& businessLine,
    vector<bool>& isActive) {

        unordered_map<string, int> mp;
        mp["electronics"] = 0;
        mp["grocery"]     = 1;
        mp["pharmacy"]    = 2;
        mp["restaurant"]  = 3;

        vector<pair<int, string>> temp;
        int n = code.size();

        for (int i = 0; i < n; i++) {
            if (isActive[i] &&
                validcode(code[i]) &&
                mp.find(businessLine[i]) != mp.end()) {

                temp.push_back({mp[businessLine[i]], code[i]});
            }
        }

        sort(temp.begin(), temp.end());

        vector<string> result;
        for (auto &p : temp) {
            result.push_back(p.second);
        }

        return result;
    }
};
