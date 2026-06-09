class Solution {
public:
    unordered_set<string>st;
    int bfs(string &bw, string& ew)
    {
        queue<string>q;
        q.push(bw);
        int turns =1;
        while(!q.empty())
        {
            int size = q.size();
            while(size--)
            {
                string word = q.front();
                if(word==ew)
                {
                    return turns;
                }
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
                                q.push(temp);
                                st.erase(temp);
                            }
                        }
                    }
                }
            }
            turns++;
        }

        return 0;
    }
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        for(auto &word:wordList)
        {
            st.insert(word);
        }
        st.erase(beginWord);
        if(!st.count(endWord))return 0;
        return bfs(beginWord,endWord);
    }
};