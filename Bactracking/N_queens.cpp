class Solution {
public:
    int n;
    bool isValid(vector<string>&board,int row,int col)
    {
        for(int i=row-1;i>=0;i--)
        {
            if(board[i][col]=='Q')
            {
                return false;
            }
        }
        for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void solve(vector<string>&board,int row,vector<vector<string>>&result){
        if(row>=n)
        {
            result.push_back(board);
            return ;
        }

        for(int col=0;col<n;col++)
        {
            if(isValid(board,row,col))
            {
                board[row][col] = 'Q';
                solve(board,row+1,result);
                board[row][col] = '.';
            }
        }
    }
    vector<vector<string>> solveNQueens(int N) {
        n=N;
        vector<string> board(n,string(n,'.'));
        vector<vector<string>>result;
        solve(board,0,result);
        return result;
    }
};
// more optimized
class Solution {
public:
    int n;

    void solve(vector<string>& board, int row, vector<vector<string>>& result,
               unordered_set<int>& diag, unordered_set<int>& cols, unordered_set<int>& antiD) {

        if(row >= n) {
            result.push_back(board);
            return;
        }

        for(int col = 0; col < n; col++) {
            int d = row + col;   
            int a = row - col;      

            if(cols.count(col) || diag.count(d) || antiD.count(a))
                continue;

            board[row][col] = 'Q';
            cols.insert(col);
            diag.insert(d);
            antiD.insert(a);

            solve(board, row + 1, result, diag, cols, antiD);
            board[row][col] = '.';
            cols.erase(col);
            diag.erase(d);
            antiD.erase(a);
        }
    }

    vector<vector<string>> solveNQueens(int N) {
        n = N;
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> result;

        unordered_set<int> diag;
        unordered_set<int> antiD;
        unordered_set<int> cols;

        solve(board, 0, result, diag, cols, antiD);

        return result;
    }
};
