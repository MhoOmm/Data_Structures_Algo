class Solution {
public:
    unordered_set<string>st;
    unordered_map<string,vector<string>>mp;
    unordered_map<string,int>level;
    vector<vector<string>>ans;
    void bfs(string &bw, string& ew)
    {
        queue<string>q;
        q.push(bw);
        level[bw] = 1;
        while(!q.empty())
        {
            string word = q.front();
            q.pop();
            for(int i=0;i<word.length();i++)
            {
                for(int j=0;j<26;j++)
                {
                    if('a'+j != word[i])
                    {
                        string temp = word;
                        temp[i] = 'a'+j;
                        if(st.count(temp))
                        {
                            if(level.find(temp)==level.end()){
                                level[temp] = level[word]+1;
                                q.push(temp);
                                mp[temp].push_back(word);
                            }else if (level[temp]==level[word]+1){ 
                                    // same already gen before
                                mp[temp].push_back(word);
                            }
                        }
                    }
                }
            }
        }
    }

    void dfs(string &word,string &bw,vector<string>&path)
    {
        path.push_back(word);
        if(word==bw) // base case
        {
            vector<string>temp = path;
            reverse(temp.begin(),temp.end());
            ans.push_back(temp);
            path.pop_back();
            return;
        }
        for(auto &parent:mp[word])
        {
            dfs(parent,bw,path);
        }
        path.pop_back(); // backtracking
    }


    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        for(auto &word:wordList)
        {
            st.insert(word);
        }
        if (!st.count(endWord))return {};
        bfs(beginWord,endWord);
        if (level.find(endWord) == level.end())
            return {};

        vector<string>path;
        dfs(endWord,beginWord,path);
        return ans;
    }
};