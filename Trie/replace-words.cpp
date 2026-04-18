class Solution {
public:
    struct trieNode{
        bool eow;
        trieNode* child[26];
    };
    trieNode* getNode(){
        trieNode* node = new trieNode();
        node->eow= false;
        for(int i=0;i<26;i++)
        {
            node->child[i]= NULL;
        }
        return node;
    }

    trieNode* root;
    void insert(string word)
    {
        trieNode* crawl = root;
        for(auto &ch:word)
        {
            int idx = ch-'a';
            if(crawl->child[idx]==NULL)
            {
                crawl->child[idx] = getNode();
            }
            crawl = crawl->child[idx];
        }
        crawl->eow = true;
    }

    string prefixS(string word)
    {
        trieNode* crawl = root;
        string prefix = "";
        for(auto &ch:word)
        {
            int idx = ch-'a';
            if(crawl->child[idx]==NULL)
            {
                return word;//no prefix is there
            }
            prefix.push_back(ch);
            crawl= crawl->child[idx];

            if(crawl->eow)
            {
                return prefix;
            }
        }

        return word;
    }

    string prefixRep(vector<string>&words,vector<string>& dictionary)
    {
        root = getNode();

        for(auto &word:dictionary)
        {
            insert(word);
        }
        string result = "";
        for(auto &word:words)
        {
            string rep = prefixS(word);
            result += rep;
            result += " ";
        }
        result.pop_back();

        return result;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        vector<string>words;
        string temp="";
        for(auto &ch:sentence){
            if(ch==' ')
            {
                words.push_back(temp);
                temp="";
                continue;
            }
            temp.push_back(ch);
        }
        words.push_back(temp);
        string ans =  prefixRep(words,dictionary);
        return ans;
    }
};