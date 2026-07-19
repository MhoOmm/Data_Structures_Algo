class Solution {
public:
    string removeDuplicateLetters(string s) {
        string result = "";
        vector<int>lastIdx(26,0);
        vector<int>visited(26,false);

        for(int i=0;i<s.length();i++)
        {
            lastIdx[s[i]-'a'] = i;
        }

        for(int i=0;i<s.length();i++)
        {
            char ch = s[i];
            int idx = s[i]-'a';
            if(visited[idx]){
                continue;
            }

            while(result.length()>0 && result.back() > ch && lastIdx[result.back()-'a']>i)
            {
                visited[result.back()-'a'] = false;
                result.pop_back();
            }

            result.push_back(ch);
            visited[idx] = true;
        }
        return result;
    }
};