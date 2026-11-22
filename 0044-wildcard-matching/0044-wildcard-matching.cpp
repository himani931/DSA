class Solution {
public:

    //recursion

    // bool solve(string& s , string& p , int i , int j){
    //     if(i < 0 && j < 0) return true;

    //     if(j < 0) return false;

    //     if(i < 0) {
    //         for(int k = 0; k <= j; k++) {
    //             if(p[k] != '*') return false;
    //         }
    //         return true;
    //     }

    //     if(s[i] == p[j] || p[j] == '?') {
    //         return solve(s , p , i-1 , j-1);
    //     } else if(p[j] == '*') {
    //         return solve(s , p , i , j-1) || solve(s , p , i-1 , j);
    //     } else{
    //         return false;
    //     }
    //     return false;
    // }

    //top down

    bool solve(string& s , string& p , int i , int j , vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;

        if(j < 0) return false;

        if(i < 0) {
            for(int k = 0; k <= j; k++) {
                if(p[k] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j] || p[j] == '?') {
            return dp[i][j] = solve(s , p , i-1 , j-1 , dp);
        } else if(p[j] == '*') {
            return dp[i][j] = solve(s , p , i , j-1 , dp) || solve(s , p , i-1 , j , dp);
        } else{
            return dp[i][j] = false;
        }
        return dp[i][j] = false;
    }

    bool isMatch(string s, string p) {
        int n = s.length();
        int m = p.length();

        vector<vector<int>>dp(n , vector<int>(m , -1));

        return solve(s , p , n-1 , m-1 , dp);
    }
};