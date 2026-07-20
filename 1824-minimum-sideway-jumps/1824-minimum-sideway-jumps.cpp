class Solution {
public:
    // recursion
    //  int solve(vector<int>& obstacles , int currlane , int pos){
    //      int n = obstacles.size() - 1;
    //      if(pos == n) return 0;
    //      if(obstacles[pos+1] != currlane) {
    //         return solve(obstacles , currlane , pos+1);
    //      } else{
    //          int ans = INT_MAX;
    //          for(int i = 1 ; i<=3 ; i++) {
    //              if(currlane != i && obstacles[pos] != i){
    //              ans = min(ans , 1 + solve(obstacles , i , pos));
    //              }
    //          }
    //           return ans;

    //     }
    // }

    // top down

    //  int solve(vector<int>& obstacles , int currlane , int pos ,
    //  vector<vector<int>> &dp){
    //     int n = obstacles.size() - 1;
    //     if(pos == n) return 0;
    //     if(dp[currlane][pos] != -1) return dp[currlane][pos];
    //     if(obstacles[pos+1] != currlane) {
    //        return solve(obstacles , currlane , pos+1 , dp);
    //     } else{
    //         int ans = INT_MAX;
    //         for(int i = 1 ; i<=3 ; i++) {
    //             if(currlane != i && obstacles[pos] != i){
    //             ans = min(ans , 1 + solve(obstacles , i , pos , dp));
    //             }
    //         }
    //         dp[currlane][pos] = ans;
    //          return dp[currlane][pos];

    //     }
    // }

    // bottom up

    // int solve(vector<int>& obstacles) {
    //     int n = obstacles.size() -1;
    //     vector<vector<int>> dp(4, vector<int>(n+1, INT_MAX));

    //     dp[0][n] = 0;
    //     dp[1][n] = 0;
    //     dp[2][n] = 0;
    //     dp[3][n] = 0;

    //     for (int pos = n - 1; pos >= 0; pos--) {
    //         for (int currlane = 1; currlane <= 3; currlane++) {
    //             if (obstacles[pos + 1] != currlane) {
    //                 dp[currlane][pos] = dp[currlane][pos + 1];
    //             } else {
    //                 int ans = INT_MAX;
    //                 for (int i = 1; i <= 3; i++) {
    //                     if (currlane != i && obstacles[pos] != i) {
    //                         ans = min(ans, 1 + dp[i][pos+1]);
    //                     }
    //                 }
    //                 dp[currlane][pos] = ans;
    //             }
    //         }
    //     }
    //     return min(dp[2][0] , min(1+dp[1][0] , 1+dp[3][0]));
    // }
    
    //so

       int solve(vector<int>& obstacles) {
        int n = obstacles.size() -1;vector<vector<int>> dp(4, vector<int>(n+1, INT_MAX));
        vector<int> curr(4 , INT_MAX);
        vector<int> next (4 , INT_MAX);

        next[0] = 0;
        next[1] = 0;
        next[2] = 0;
        next[3] = 0;

        for (int pos = n - 1; pos >= 0; pos--) {
            for (int currlane = 1; currlane <= 3; currlane++) {
                if (obstacles[pos + 1] != currlane) {
                    curr[currlane] = next[currlane];
                } else {
                    int ans = INT_MAX;
                    for (int i = 1; i <= 3; i++) {
                        if (currlane != i && obstacles[pos] != i) {
                            ans = min(ans, 1 + next[i]);
                        }
                    }
                    curr[currlane] = ans;
                }
            }
            next = curr;
        }
        return min(next[2] , min(1+next[1] , 1+next[3]));
    }

        int minSideJumps(vector<int> & obstacles) {
            // vector<vector<int>> dp(4 , vector<int> (obstacles.size() , -1));
            return solve(obstacles);
        }
    };