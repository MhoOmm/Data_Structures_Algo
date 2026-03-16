class Solution {
public:
    int n,m;
    vector<vector<int>>directions{{0,1},{0,-1},{1,0},{-1,0}};
    bool dfs(string word,vector<vector<char>>& board,int i,int j,int idx)
    {
        if(idx==word.length())//base case
        {
            return true;// abhi tak sab match hogya
        }
        if(i<0 || i>=m || j<0 || j>=n || board[i][j]=='$')//boundary check
        {
            return false;
        }

        if(board[i][j]!=word[idx])return false;

        // mark the place
        char temp = board[i][j];
        board[i][j] = '$';
        for(auto &dir:directions)
        {
            int ni= i+ dir[0];
            int nj = j+ dir[1];
            if (dfs(word,board,ni,nj,idx+1))
            {
                return true;
            }
        }
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0])
                {
                    if(dfs(word,board,i,j,0)){
                        return true;
                    }
                }
            }
        }

        return false;
    }
};