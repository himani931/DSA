class Solution {
public:

    bool isSafe(int row , int col , vector<vector<char>> &board , char v) {
        
        for(int i = 0 ; i< 9 ; i++) {
            //row
            if(board[row][i] == v) return false;
            //col
            if(board[i][col] == v) return false;

            //matrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == v) return false;
        }
        return true;
    }

    bool solve(vector<vector<char>> &board) {
        for(int i = 0 ; i < 9 ; i++) {
            for(int j = 0 ; j < 9 ; j++) {
               if(board[i][j] == '.') {
                for(char v = '1' ; v <= '9' ; v++) {
                     if(isSafe(i , j , board , v)) {
                    board[i][j] = v;
                    if(solve(board))
                                return true;

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