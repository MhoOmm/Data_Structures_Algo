class Solution {
public:
    struct trieNode{
        bool eow;
        trieNode* child[26];
    };
    trieNode* getNode()
    {
        trieNode* node = new trieNode();
        node->eow = false;
        for(int i=0;i<26;i++)
        {
            node->child[i] = NULL;
        }
        return node;
    }
    void insert(string word,trieNode* root)
    {
        trieNode* crawl = root;
        for(auto &ch:word)
        {
            int idx = ch-'a';
            if(crawl->child[idx] == NULL)
            {
                crawl->child[idx] = getNode();
            }
            crawl = crawl->child[idx];
        }
        crawl->eow = true;
    }
    bool search(string word,trieNode* root){
        trieNode* crawl = root;
        for(auto &ch:word)
        {
            int idx = ch-'a';
            if(crawl->child[idx]==NULL)
            {
                return false;
            }
            crawl = crawl->child[idx];
        }

        return true;
    }
    void deleteTrie(trieNode* node)
    {
        if(node==NULL)
        {
            return;
        }
        for(int i=0;i<26;i++)
        {
            deleteTrie(node->child[i]);
        }
        delete node;
    }
    int countPrefixSuffixPairs(vector<string>& words) {
        int n = words.size();
        int count =0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                // Prefix
                trieNode* root1 = getNode();
                insert(words[i],root1);
                bool searchPrefix = search(words[j],root1);
                deleteTrie(root1);
                // suffix
                trieNode* root2 = getNode();
                string temp = words[i];
                reverse(temp.begin(),temp.end());
                insert(temp,root2);
                string temp2 = words[j];
                reverse(temp2.begin(),temp2.end());
                bool searchSuffix = search(temp2,root2);
                deleteTrie(root2);
                if(searchSuffix && searchPrefix){
                    count++;
                }
                
            }
        }

        return count;
    }
};