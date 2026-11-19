class Solution {
public:
    // recursion
    // int solve(string s1, string s2, int i, int j) {
    //     if (i == s1.length())
    //         return 0;
    //     if (j == s2.length())
    //         return 0;
    //     int ans = 0;
    //     if (s1[i] == s2[j]) {
    //         ans = 1 + solve(s1, s2, i + 1, j + 1);
    //     } else {
    //         ans = max(solve(s1, s2, i, j + 1), solve(s1, s2, i + 1, j));
    //     }
    //     return ans;
    // }

    // top down

    // int solve(string s1, string s2, int i, int j, vector<vector<int>>& dp) {
    //     if (i == s1.length())
    //         return 0;
    //     if (j == s2.length())
    //         return 0;

    //     if (dp[i][j] != -1)
    //         return dp[i][j];
    //     int ans = 0;
    //     if (s1[i] == s2[j]) {
    //         ans = 1 + solve(s1, s2, i + 1, j + 1, dp);
    //     } else {
    //         ans = max(solve(s1, s2, i, j + 1, dp), solve(s1, s2, i + 1, j, dp));
    //     }
    //     return dp[i][j] = ans;
    // }

    // bottom up

    // int solve(string s1, string s2) {
    //     int n = s1.length();
    //     int m = s2.length();
    //     vector<vector<int>> dp(n+1 , vector<int>(m+1, 0));

    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int j = m - 1; j >= 0; j--) {
    //             int ans = 0;
    //             if (s1[i] == s2[j]) {
    //                 ans = 1 + dp[i + 1][j + 1];
    //             } else {
    //                 ans = max(dp[i][j + 1],
    //                           dp[i + 1][j]);
    //             }
    //              dp[i][j] = ans;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //space optimization

    int solve(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int>curr(m+1 , 0);
        vector<int> next(m+1 ,0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (s1[i] == s2[j]) {
                    ans = 1 + next[j + 1];
                } else {
                    ans = max(curr[j + 1],
                              next[j]);
                }
                 curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }

    int longestCommonSubsequence(string text1, string text2) {
        // int n = text1.length();
        // int m = text2.length();
        // vector<vector<int>> dp(n , vector<int> (m , -1));
        // return solve(text1, text2, 0, 0, dp);
        return solve(text1 , text2);
    }
};