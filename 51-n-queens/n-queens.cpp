class Solution {
public:
     bool issafe(int row , int col , vector<string>& board , int n){

       for (int j = col - 1; j >= 0; j--) {
    if (board[row][j] == 'Q') return false;
}
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
            if (board[i][j] == 'Q') return false;
        }

        for (int i = row + 1, j = col - 1; i < n && j >= 0; i++, j--) {
            if (board[i][j] == 'Q') return false;
        }
        return true;

    }
    void solve(int col, vector<string>& board, vector<vector<string>>& ans, int n) {
        if (col == n) {
            ans.push_back(board);
            return;
        }

        for (int row = 0; row < n; row++) {
            if (issafe(row, col, board, n)) {
                board[row][col] = 'Q';       
                solve(col + 1, board, ans, n); 
                board[row][col] = '.';   
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
         vector<string> board(n, string(n, '.'));
         solve(0, board, ans, n);
         return ans;
    }
};