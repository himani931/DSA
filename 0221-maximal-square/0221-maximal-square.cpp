class Solution {
public:
    // recursion

    // int solve(vector<vector<char>>& matrix , int i , int j , int &maxi) {
    //     if(i >= matrix.size() || j >= matrix[0].size()) return 0;
    //     int right = solve(matrix , i , j+1 , maxi);
    //     int diagnol = solve(matrix , i+1 , j+1 , maxi);
    //     int down = solve(matrix, i+1 , j , maxi);
    //     if(matrix[i][j] == '1') {
    //         int ans = 1 + min(right , min(diagnol , down));
    //         maxi = max(ans , maxi);
    //         return ans;
    //     } else {
    //         return 0;
    //     }
    // }

    // top down

    //  int solve(vector<vector<char>>& matrix , int i , int j , int &maxi ,
    //  vector<vector<int>> &dp) {
    //     if(i >= matrix.size() || j >= matrix[0].size()) return 0;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     int right = solve(matrix , i , j+1 , maxi , dp);
    //     int diagnol = solve(matrix , i+1 , j+1 , maxi , dp);
    //     int down = solve(matrix, i+1 , j , maxi , dp);
    //     if(matrix[i][j] == '1') {
    //         dp[i][j] = 1 + min(right , min(diagnol , down));
    //         maxi = max(dp[i][j] , maxi);
    //         return dp[i][j];
    //     } else {
    //         return dp[i][j] = 0;
    //     }
    // }

    // bottom up

    int solve(vector<vector<char>>& matrix , int &maxi) {
        int n = matrix.size();
        int m = matrix[0].size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        for (int i = n-1 ; i >= 0; i--) {
            for (int j = m-1 ; j >= 0; j--) {
                int right = dp[i][j+1];
                int diagnol = dp[i + 1][j + 1];
                int down = dp[i + 1][j];
                if (matrix[i][j] == '1') {
                    dp[i][j] = 1 + min(right, min(diagnol, down));
                    maxi = max(dp[i][j], maxi);
                } else {
                   dp[i][j] = 0;
                }
            }
        }
        return dp[0][0];
    }

    int maximalSquare(vector<vector<char>>& matrix) {
        int maxi = 0;
        // int n = matrix.size();
        // int m = matrix[0].size();
        // vector<vector<int>> dp( n, vector<int> (m , -1));
        // solve(matrix, 0, 0, maxi);
        solve(matrix , maxi);
        return maxi * maxi;
    }
};