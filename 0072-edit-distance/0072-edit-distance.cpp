class Solution {
public:
    // recursion
    // int solve(string& word1 , string& word2 , int i , int j) {
    //     int n = word1.length();
    //     int m = word2.length();

    //     if(i == n) return m - j;
    //     if(j == m) return n - i;
    //     int ans = 0;

    //     if(word1[i] == word2[j]) {
    //         return solve(word1 , word2 , i+1 , j+1);
    //     } else {
    //         int insertAns = 1 + solve(word1 , word2 , i , j+1);
    //         int deleteAns = 1 + solve(word1 , word2 , i+1 , j);
    //         int replaceAns = 1 + solve(word1 , word2 , i+1 , j+1);

    //         ans = min(insertAns , min(deleteAns , replaceAns));
    //     }
    //     return ans;
    // }

    // top down
    //  int solve(string& word1 , string& word2 , int i , int j ,
    //  vector<vector<int>> &dp) {
    //      int n = word1.length();
    //      int m = word2.length();

    //     if(i == n) return m - j;
    //     if(j == m) return n - i;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int ans = 0;

    //     if(word1[i] == word2[j]) {
    //         return solve(word1 , word2 , i+1 , j+1 , dp);
    //     } else {
    //         int insertAns = 1 + solve(word1 , word2 , i , j+1 , dp);
    //         int deleteAns = 1 + solve(word1 , word2 , i+1 , j , dp);
    //         int replaceAns = 1 + solve(word1 , word2 , i+1 , j+1 , dp);

    //         ans = min(insertAns , min(deleteAns , replaceAns));
    //     }
    //     return dp[i][j] = ans;
    // }

    // bottom up

    // int solve(string& word1, string& word2) {
    //     int n = word1.length();
    //     int m = word2.length();

    //     vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    //     // Base cases
    //     for (int i = 0; i <= n; i++) {
    //         dp[i][m] = n - i;
    //     }

    //     for (int j = 0; j <= m; j++) {
    //         dp[n][j] = m - j;
    //     }

    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int j = m - 1; j >= 0; j--) {
    //             int ans = 0;
    //             if (word1[i] == word2[j]) {
    //                 ans = dp[i + 1][j + 1];
    //             } else {
    //                 int insertAns = 1 + dp[i][j + 1];
    //                 int deleteAns = 1 + dp[i + 1][j];
    //                 int replaceAns = 1 + dp[i + 1][j + 1];

    //                 ans = min(insertAns, min(deleteAns, replaceAns));
    //             }
    //             dp[i][j] = ans;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //space optimization

    int solve(string& word1, string& word2) {
        int n = word1.length();
        int m = word2.length();

         vector<int> curr(m + 1, 0);
         vector<int> next(m + 1 , 0);

        // Base cases

        for (int j = 0; j <= m; j++) {
            next[j] = m - j;
        }

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                //from base case
                curr[m] = n - i;

                int ans = 0;
                if (word1[i] == word2[j]) {
                    ans = next[j + 1];
                } else {
                    int insertAns = 1 + curr[j + 1];
                    int deleteAns = 1 + next[j];
                    int replaceAns = 1 + next[j + 1];

                    ans = min(insertAns, min(deleteAns, replaceAns));
                }
                curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        // vector<vector<int>> dp(n, vector<int>(m, -1));
        // return solve(word1, word2, 0, 0, dp);
        if(n == 0) return m;
        if(m == 0) return n;
        return solve(word1, word2);
    }
};