class Solution {
public:
    bool isvalid(vector<vector<char>>& board , int row , int col , int num){
        for(int i = 0 ; i < 9 ; i++){
            if(board[row][i] == num)return false;
            if(board[i][col] == num) return false;
        }

            int startrow = row - row % 3;;
            int startcol = col - col % 3;

            for(int i = 0 ; i < 3 ; i++){
                for(int j = 0 ; j < 3 ; j++){
                    if(board[startrow + i][startcol + j] == num){
                        return false;
                    }
                }
            }
            return true;
        }
    

    bool solve(vector<vector<char>>& board){
        for(int i = 0 ; i < 9 ; i++){
            for(int j = 0 ; j < 9 ; j++ ){
                if(board[i][j] == '.'){
                    for(char num = '1'; num <= '9' ; num++){
                        if(isvalid(board, i, j,num)){
                            board[i][j] = num;
                            if(solve(board))return true;
                            board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};