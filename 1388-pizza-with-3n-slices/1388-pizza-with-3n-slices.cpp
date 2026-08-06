class Solution {
public:

//recursion

    // int solve(int i ,int end , vector<int> &slices , int n) {
    //     if(n == 0 || i > end) return 0;

    //     int take = slices[i] + solve(i+2 , end , slices , n-1);
    //     int notTake = 0 + solve(i+1 , end , slices , n);
    //     return max(take , notTake);
    // }

    //top down

     int solve(int i ,int end , vector<int> &slices , int n , vector<vector<int>> &dp) {
        if(n == 0 || i > end) return 0;

        if(dp[i][n] != -1) return dp[i][n];

        int take = slices[i] + solve(i+2 , end , slices , n-1 , dp);
        int notTake = 0 + solve(i+1 , end , slices , n , dp);
        dp[i][n] = max(take , notTake);

        return dp[i][n];
    }

    int maxSizeSlices(vector<int>& slices) {
        int k = slices.size();
        vector<vector<int>> dp(k , vector<int> (k , -1));
        int case1 = solve(0 , k-2, slices , k/3 , dp);
          for (int i = 0; i < k; i++) {
        fill(dp[i].begin(), dp[i].end(), -1);
    }
        int case2 = solve(1 , k-1,  slices , k/3 , dp);
        return max(case1 , case2);
    }
};