class Solution {
public:
    struct trie{
        trie* child[26]; 
        int count;
        int eow = false;
    };
    trie* root ;
    trie* getNode(){
        trie* newn = new trie();
        newn->count = 0;
        newn->eow = false;
        for(int i=0;i<26;i++)
        {
            newn->child[i] = NULL;
        }
        return newn;
    }

    void insert(string word)
    {
        trie* crawl = root;
        for(int i =0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(crawl->child[idx] == NULL )
            {
                crawl->child[idx] = getNode();
            }
            crawl = crawl->child[idx];
            crawl->count++;
        }
    }

    int getscore(string word)
    {
        int co=0;
        trie* crawl  = root;
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i] - 'a';
            if(crawl->child[idx] == NULL)
            {
                return co;
            }
            crawl = crawl->child[idx];
            co+=crawl->count;
        }
        return co;
    }
    vector<int> sumPrefixScores(vector<string>& words) {
        int n = words.size();
        root = getNode();

        for(auto &word:words)
        {
            insert(word);
        }

        vector<int>result(n,0);
        for(int i=0;i<n;i++)
        {
            result[i] = getscore(words[i]);
        }

        return result;
    }
};