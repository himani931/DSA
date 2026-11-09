class Solution {
public:

   // recursion
    //  int solve(int i , int buy , int limit , vector<int>& prices) {
    //      if(i == prices.size()) return 0;
    //      if(limit == 0) return 0;

    //     int profit = 0;

    //     if(buy) {
    //         profit = max((-prices[i] + solve(i + 1 , 0 , limit , prices)) ,( 0 +
    //         solve(i + 1 , 1 , limit , prices)));
    //     }

    //     else {
    //         profit = max((prices[i] + solve(i+1 , 1 , limit-1 , prices)) ,( 0 + solve(i
    //         + 1 , 0 , limit, prices)));
    //     }
    //     return profit;
    // }

    // top down
    // int solve(int i , int buy , int limit , vector<int>& prices , vector<vector<vector<int>>> &dp) {
    //      if(i == prices.size()) return 0;
    //      if(limit == 0) return 0;

    //      if(dp[i][buy][limit] != -1) return dp[i][buy][limit];

    //     int profit = 0;

    //     if(buy) {
    //         profit = max((-prices[i] + solve(i + 1 , 0 , limit , prices , dp)) ,( 0 +
    //         solve(i + 1 , 1 , limit , prices , dp)));
    //     }

    //     else {
    //         profit = max((prices[i] + solve(i+1 , 1 , limit-1 , prices , dp)) ,( 0 + solve(i
    //         + 1 , 0 , limit, prices , dp)));
    //     }
    //     dp[i][buy][limit] = profit;
    //      return dp[i][buy][limit];
    // }

    // bottom up
    int solve(vector<int>& prices) {
        int n = prices.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2, vector<int>(3 , 0)));

        for (int i = n - 1; i >= 0; i--) {
            for (int buy = 0; buy <= 1; buy++) {
                for(int limit = 1 ; limit <= 2 ; limit++) {
                    int profit = 0;

                if (buy) {
                    profit = max((-prices[i] + dp[i + 1][0][limit]),
                                 (0 + dp[i + 1][1][limit]));
                }

                else {
                    profit = max((prices[i] + dp[i + 1][1][limit-1]),
                                 (0 + dp[i + 1][0][limit]));
                }
                dp[i][buy][limit] = profit;
                }
            }
        }
        return dp[0][1][2];
    }

    // //space optimization

    // int solve(vector<int>& prices) {
    //     int n = prices.size();
        
    //     vector<int> curr(2 , 0);
    //     vector<int> next(2 , 0);

    //     for (int i = n - 1; i >= 0; i--) {
    //         for (int buy = 0; buy <= 1; buy++) {
    //             int profit = 0;

    //             if (buy) {
    //                 profit = max((-prices[i] + next[0]),
    //                              (0 + next[1]));
    //             }

    //             else {
    //                 profit = max((prices[i] + next[1]),
    //                              (0 + next[0]));
    //             }
    //            curr[buy] = profit;
    //         }
    //         next = curr;
    //     }
    //     return next[1];
    // }

    int maxProfit(vector<int>& prices) {
        // int n = prices.size();
        // vector<vector<vector<int>>>dp(n , vector<vector<int>>(2 , vector<int>(3 , -1)));
        // return solve(0 , 1 , 2 , prices , dp);
        return solve(prices);
    }
};