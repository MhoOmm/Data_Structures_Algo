class Solution {
public:

    struct trieNode{
        bool eow = false;
        trieNode* child[26];
    };
    trieNode* getNode(){
        trieNode* newn = new trieNode();
        newn->eow = false;
        for(int i =0;i<26;i++)
        {
            newn->child[i] = NULL;
        }
        return newn;
    }
    trieNode* root;
    void insert(string word){
        trieNode* crawl = root;
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(crawl->child[idx]==NULL)
            {
                crawl->child[idx] = getNode();
            }
            crawl = crawl->child[idx];
        }
        crawl->eow = true;
    }
    string search(string prefix)
    {
        trieNode* crawl = root;
        for(int i=0;i<prefix.length();i++)
        {
            int idx = prefix[i]-'a';
            if(crawl->child[idx]==NULL)
            {
                return prefix;
            }
            crawl = crawl->child[idx];
            if(crawl->eow == true)
            {
                return prefix.substr(0,i+1);
            }
        }
        return prefix;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {

        stringstream ss(sentence);
        string word;
        string result;

        root = getNode();
        for(auto &word:dictionary)
        {
            insert(word);
        }

        while(getline(ss,word,' '))
        {
            result+= search(word) + ' ';
        }
        result.pop_back();// to remove the last space
        return result;
    }
};