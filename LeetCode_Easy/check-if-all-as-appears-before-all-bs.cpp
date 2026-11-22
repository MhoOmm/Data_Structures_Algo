class Solution {
public:
    bool checkString(string s) {
        bool aflg = true;
        for (auto &ch : s)
        {
            if(ch=='b')
            {
                aflg = false;
            }
            if(aflg==false && ch=='a')
            {
                return false;
            }
        }
        return true;
    }
};