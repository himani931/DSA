class Solution {
public:

    bool isSafe(int i , int j , vector<string> &board , int n) {
        int x = i ; //row
        int y = j; //col
        //check for row
        while(y>=0) {
            if(board[x][y] == 'Q') {
                return false;
            }
            y--;
        }
    //check for diagonal
    x=i;
    y=j;
    //upper
    while(x>=0 && y>=0) {
         if(board[x][y] == 'Q') {
                return false;
            }
            y--;
            x--;
    }
    //lower
    x=i;
    y=j;
    while(x<n && y>=0) {
         if(board[x][y] == 'Q') {
                return false;
            }
            y--;
            x++;
    }
    return true;
    }

    void solve(int col , vector<vector<string>> &ans , vector<string> &board , int n) {
        if(col == n) {
           ans.push_back(board);
            return;
        }

        for(int i = 0 ; i < n ; i++) {
            if(isSafe(i , col , board , n)) {
                board[i][col] = 'Q';
                solve(col+1 , ans , board , n);
                //backtrack
                board[i][col] = '.';
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