class Solution {
public:
    struct trie {
        trie* child[26] ;
        int count ;
    };
    trie* root ;
    trie* getNode(){
        trie* newn = new trie();
        newn -> count =0;
        for(int i=0;i<26;i++)
        {
            newn->child[i] = NULL;
        }
        return newn;
    }
    void insert(string word)
    {
        trie* crawl  = root;
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i] - 'a';
            if(crawl->child[idx]==NULL)
            {
               crawl->child[idx] = getNode(); 
            }
            crawl = crawl->child[idx];
            crawl->count++;
        }
    }

    int getCount(string word)
    {
        trie* crawl = root;
        int co = crawl->count; //parent ka
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(crawl->child[idx]==NULL){
                return 0;
            }
            crawl = crawl->child[idx];
            co = crawl->count;//child ka
        }
        return co;
    }
    int prefixCount(vector<string>& words, string pref) {
        int n = words.size();
        root = getNode();
        for(int i=0;i<n;i++)
        {
            insert(words[i]);
        } 

        return getCount(pref);
    }
};