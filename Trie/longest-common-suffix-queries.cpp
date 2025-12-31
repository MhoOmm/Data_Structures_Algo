class Solution {
public:
    struct trie{
        int index;
        trie* child[26];
    };
    trie*root;
    int shortestIndex;
    trie* getNode(){
        trie* newn = new trie();
        newn->index = -1;
        for(int i=0;i<26;i++)
        {
            newn->child[i] = NULL; 
        }
        return newn;
    }

    void insert(const string& word,int j,vector<string>& Cont){
        trie* crawl = root;
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(crawl->child[idx]==NULL)
            {
                crawl->child[idx] = getNode(); 
            }
            crawl = crawl->child[idx];
            if(crawl->index==-1)
            {
                crawl->index = j;
            }else{
                int k = crawl->index;
                int nitem = word.length();
                int exist = Cont[k].length();
                if(nitem<exist){
                    crawl->index = j;
                }
            }
        }
    }

    int suffixindex(const string& word)
    {
        trie* crawl = root;
        int j= shortestIndex;
        for(int i=0;i<word.length();i++)
        {
            int idx = word[i]-'a';
            if(crawl->child[idx] == NULL)
            {
                return j;
            }
            crawl  = crawl->child[idx];
            j = crawl->index;
        }

        return j;
    }
    vector<int> stringIndices(vector<string>& Cont, vector<string>& Query) {

        int n = Cont.size();
        int idx = -1;
        int max = INT_MAX;
        root = getNode();
        for(int i =0;i<n;i++)
        {
            int temp = Cont[i].length();
            if(temp<max)
            {
                max = temp;
                idx = i;
            }
        }
        shortestIndex = idx;
        for(int i=0;i<n;i++)
        {
            string word= Cont[i];
            reverse(word.begin(), word.end());
            insert(word, i, Cont);
        }
        vector<int>ans;
        for(int i=0;i<Query.size();i++)
        {
            string rev = Query[i];
            reverse(rev.begin(),rev.end());
            ans.push_back(suffixindex(rev));
        }
        return ans;
    }
};