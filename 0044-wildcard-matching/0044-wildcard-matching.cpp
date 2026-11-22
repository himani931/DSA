class Solution {
public:
    // recursion

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

    // top down

    // bool solve(string& s, string& p, int i, int j, vector<vector<int>>& dp) {
    //     if (i < 0 && j < 0)
    //         return true;

    //     if (j < 0)
    //         return false;

    //     if (i < 0) {
    //         for (int k = 0; k <= j; k++) {
    //             if (p[k] != '*')
    //                 return false;
    //         }
    //         return true;
    //     }

    //     if (dp[i][j] != -1)
    //         return dp[i][j];

    //     if (s[i] == p[j] || p[j] == '?') {
    //         return dp[i][j] = solve(s, p, i - 1, j - 1, dp);
    //     } else if (p[j] == '*') {
    //         return dp[i][j] =
    //                    solve(s, p, i, j - 1, dp) || solve(s, p, i - 1, j, dp);
    //     } else {
    //         return dp[i][j] = false;
    //     }
    //     return dp[i][j] = false;
    // }

    // bottom up

    // int solve(string& s, string& p) {
    //     int n = s.length();
    //     int m = p.length();

    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //      // Base case
    //     dp[0][0] = true;

    //     // When string is empty, pattern must contain only *
    //     for(int j = 1; j <= m; j++) {
    //         if(p[j-1] == '*') {
    //             dp[0][j] = dp[0][j-1];
    //         }
    //     }

    //      for(int i = 1; i <= n; i++) {
    //         for(int j = 1; j <= m; j++) {

    //             if(s[i-1] == p[j-1] || p[j-1] == '?') {
    //                 dp[i][j] = dp[i-1][j-1];
    //             }
    //             else if(p[j-1] == '*') {
    //                 dp[i][j] = dp[i][j-1] ||
    //                            dp[i-1][j];
    //             }
    //             else {
    //                 dp[i][j] = false;
    //             }
    //         }
    //     }

    //     return dp[n][m];
    // }

    // Space Optimization
    bool solve(string& s, string& p) {
        int n = s.length();
        int m = p.length();

        vector<int> curr(m + 1, 0);
        vector<int> next(m + 1, 0);

        // Base case
        curr[0] = true;

        // When string is empty, pattern must contain only *
        for(int j = 1; j <= m; j++) {
            if(p[j-1] == '*') {
                curr[j] = curr[j-1];
            }
        }

        for(int i = 1; i <= n; i++) {

            next[0] = false;

            for(int j = 1; j <= m; j++) {

                if(s[i-1] == p[j-1] || p[j-1] == '?') {
                    next[j] = curr[j-1];
                }
                else if(p[j-1] == '*') {
                    next[j] = next[j-1] || curr[j];
                }
                else {
                    next[j] = false;
                }
            }

            curr = next;
        }

        return curr[m];
    }

    bool isMatch(string s, string p) {
        // int n = s.length();
        // int m = p.length();

        // vector<vector<int>> dp(n, vector<int>(m, -1));

        // return solve(s, p, n - 1, m - 1, dp);

        return solve(s , p);
    }
};