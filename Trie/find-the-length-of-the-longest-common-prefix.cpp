class Solution {
public:
    struct trie{
        bool eow ; 
        trie* child[10];
    };
    trie* root;
    trie* getNode(){
        trie* newn = new trie();
        newn -> eow = false;
        for(int i =0;i<10;i++)
        {
            newn->child[i] = NULL;
        }
        return newn;
    }
    void insert(int num)
    {
        trie* crawl = root;
        string s = to_string(num);
        for(int i=0;i<s.length();i++){
            int idx = s[i]-'0';
            if(crawl->child[idx]==NULL)
            {
                crawl->child[idx] = getNode();  
            }
            crawl = crawl->child[idx];
        }
        crawl->eow = true;
    }

    int match(int num){
        trie* crawl = root;
        string s = to_string(num);
        int length =0;
        for(int i =0;i<s.length();i++)
        {
            int idx = s[i]-'0';
            if(crawl->child[idx]==NULL)
            {
                return length;
            }
            crawl = crawl->child[idx];
            length++;
        }

        return length;
    }
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        int result = 0;
        root = getNode();
        for(int num:arr1)
        {
            insert(num);
        }

        for(int num:arr2){
            int matchL = match(num);
            result = max(result,matchL);
        }

        return result;
    }
};