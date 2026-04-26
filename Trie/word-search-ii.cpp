class Solution {
public:
    int m,n;
    vector<string>ans;
    struct trieNode{
        bool eow;
        trieNode* child[26];
        string word;
    };
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    trieNode* getNode()
    {
        trieNode* node = new trieNode();
        node->word = "";
        node->eow = false;
        for(int i=0;i<26;i++)
        {
            node->child[i] = NULL;
        }
        return node; 
    }
    trieNode* root ;
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
        crawl->word = word;
    }
    void dfs(trieNode* root,int i,int j,vector<vector<char>>&board)
    {
        if(i>=m || j>=n || i<0 || j<0 ||board[i][j]=='$')
        {
            return;
        }
        char ch = board[i][j];
        if(root->child[ch-'a']==NULL)
        {
            return;
        }
        root = root->child[ch-'a'];
        if(root->eow==true)
        {
            string w = root->word;
            ans.push_back(w);
            root->eow = false;
        }
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir:directions){
            int ni = i + dir[0];
            int nj = j + dir[1];
            dfs(root,ni,nj,board);
        }
        board[i][j] = temp;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        m = board.size();
        n = board[0].size();
        root = getNode();
        for(auto &word:words)
        {
            insert(word);
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                char ch = board[i][j];
                if(root->child[ch-'a']!=NULL)
                {
                    dfs(root,i,j,board);
                }
            }
        }
        return ans;
    }
};