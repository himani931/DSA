class Solution {
public:

    // bool isSafe(int i , int j , vector<string> &board , int n) {
    //     int x = i ; //row
    //     int y = j; //col
    //     //check for row
    //     while(y>=0) {
    //         if(board[x][y] == 'Q') {
    //             return false;
    //         }
    //         y--;
    //     }
    // //check for diagonal
    // x=i;
    // y=j;
    // //upper
    // while(x>=0 && y>=0) {
    //      if(board[x][y] == 'Q') {
    //             return false;
    //         }
    //         y--;
    //         x--;
    // }
    // //lower
    // x=i;
    // y=j;
    // while(x<n && y>=0) {
    //      if(board[x][y] == 'Q') {
    //             return false;
    //         }
    //         y--;
    //         x++;
    // }
    // return true;
    // }

    // void solve(int col , vector<vector<string>> &ans , vector<string> &board , int n) {
    //     if(col == n) {
    //        ans.push_back(board);
    //         return;
    //     }

    //     for(int i = 0 ; i < n ; i++) {
    //         if(isSafe(i , col , board , n)) {
    //             board[i][col] = 'Q';
    //             solve(col+1 , ans , board , n);
    //             //backtrack
    //             board[i][col] = '.';
    //         }
    //     }
    // }

    bool isSafe(int row , int col , int n , vector<string> &board) {
        //horizontal
        for(int i = 0 ; i < n ; i++) {
            if(board[i][col] == 'Q') return false;
        }

        //vertical
        for(int j = 0 ; j < n ; j++) {
            if(board[row][j] == 'Q') return false;
        }

        //diagonal
        //left
        int x = row ;
        int y = col;

        while(x >= 0 && y >= 0) {
            if(board[x][y] == 'Q') return false;
            x--;
            y--;
        }

        //right
        x = row;
        y = col;

        while(x >= 0 && y < n) {
            if(board[x][y] == 'Q') return false;
            x--;
            y++;
        }
        return true;
    }

    void solve(int row , vector<vector<string>> &ans , vector<string> &board , int n) {
        if(row >= n) {
            ans.push_back(board);
            return;
        }


        for(int i = 0 ; i < n ; i++) {
            if(isSafe(row , i , n , board)) {
                board[row][i] = 'Q';
                solve(row+1 , ans , board , n);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
       vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        solve(0 , ans , board , n);
        return ans;
    }
};