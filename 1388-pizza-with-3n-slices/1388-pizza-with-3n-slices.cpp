class Solution {
public:
    // recursion

    // int solve(int i ,int end , vector<int> &slices , int n) {
    //     if(n == 0 || i > end) return 0;

    //     int take = slices[i] + solve(i+2 , end , slices , n-1);
    //     int notTake = 0 + solve(i+1 , end , slices , n);
    //     return max(take , notTake);
    // }

    // top down

    //  int solve(int i ,int end , vector<int> &slices , int n ,
    //  vector<vector<int>> &dp) {
    //     if(n == 0 || i > end) return 0;

    //     if(dp[i][n] != -1) return dp[i][n];

    //     int take = slices[i] + solve(i+2 , end , slices , n-1 , dp);
    //     int notTake = 0 + solve(i+1 , end , slices , n , dp);
    //     dp[i][n] = max(take , notTake);

    //     return dp[i][n];
    // }

    // bottom up

    int solve(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp1(k+2, vector<int>(k, 0));
        vector<vector<int>> dp2(k+2, vector<int>(k, 0));

        for (int i = k - 2; i >= 0; i--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[i] + dp1[i + 2][n - 1];
                int notTake = 0 + dp1[i + 1][n];
                dp1[i][n] = max(take, notTake);
            }
        }

        int case1 = dp1[0][k/3];


        for (int i = k - 1; i >= 1; i--) {
            for (int n = 1; n <= k / 3; n++) {
                int take = slices[i] + dp2[i + 2][n - 1];
                int notTake = 0 + dp2[i + 1][n];
                dp2[i][n] = max(take, notTake);
            }
        }

        int case2 = dp2[1][k/3];



        return max(case1 , case2);
    }

    int maxSizeSlices(vector<int>& slices) {
        // int k = slices.size();
        // // vector<vector<int>> dp(k , vector<int> (k , -1));
        // int case1 = solve(0, k - 2, slices, k / 3);
        // //       for (int i = 0; i < k; i++) {
        // //     fill(dp[i].begin(), dp[i].end(), -1);
        // // }
        // int case2 = solve(1, k - 1, slices, k / 3);
        // return max(case1, case2);

        return solve(slices);
    }
};