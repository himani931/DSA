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

    //top down
    int solve(string& word1 , string& word2 , int i , int j , vector<vector<int>> &dp) {
        int n = word1.length();
        int m = word2.length();

        if(i == n) return m - j;
        if(j == m) return n - i;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;

        if(word1[i] == word2[j]) {
            return solve(word1 , word2 , i+1 , j+1 , dp);
        } else {
            int insertAns = 1 + solve(word1 , word2 , i , j+1 , dp);
            int deleteAns = 1 + solve(word1 , word2 , i+1 , j , dp);
            int replaceAns = 1 + solve(word1 , word2 , i+1 , j+1 , dp);

            ans = min(insertAns , min(deleteAns , replaceAns));
        }
        return dp[i][j] = ans;
    }

    int minDistance(string word1, string word2) {
        int n = word1.length();
        int m = word2.length();

        vector<vector<int>> dp (n , vector<int>(m , -1));
        return solve(word1 , word2 , 0 , 0 , dp);
    }
};