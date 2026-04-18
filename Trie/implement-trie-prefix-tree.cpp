class Trie {
public:
    struct trieNode{
        bool eow;
        trieNode* children[26];
    };

    trieNode* getNode(){
        trieNode* node = new trieNode();
        node->eow= false;
        for(int i=0;i<26;i++)
        {
            node->children[i] = NULL;
        }
        return node;
    }

    trieNode* root;
    Trie() {
        root = getNode();
    }
    
    void insert(string word) {
        trieNode* crawl = root;
        for(auto &ch:word)
        {
            if(crawl->children[ch-'a']== NULL)
            {
                crawl->children[ch-'a']= getNode();
            }
            crawl = crawl->children[ch-'a'];
        }
        crawl->eow = true;
    }
    
    bool search(string word) {
        trieNode* crawl = root;
        for(auto &ch:word)
        {
            if(crawl->children[ch-'a']== NULL)
            {
                return false;
            }
            crawl = crawl->children[ch-'a'];
        }
        return crawl->eow ;
    }
    
    bool startsWith(string prefix) {
        trieNode* crawl = root;
        int count =0;
        for(auto &ch:prefix)
        {
            if(crawl->children[ch-'a']== NULL)
            {
                return false;
            }
            crawl = crawl->children[ch-'a'];
            count++;
        }
        return (count == prefix.length())?true:false; 
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */