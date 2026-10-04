class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        int n = s.length();
        unordered_map<string,string>mp;
        for(auto &pair:knowledge)
        {
            mp[pair[0]] = pair[1];
        }

        string result = "";
        int i=0;
        while(i<n){
            if(isalpha(s[i]))
            {
                result.push_back(s[i]);
            }
            else
            {
                i++;
                string temp="";
                while(s[i]!=')')
                {
                    temp.push_back(s[i]);
                    i++;
                }
                if(mp.count(temp))
                {
                    result+=mp[temp];
                }else{
                    result.push_back('?');
                }
            }
            i++;
        }
        return result;
    }
};  