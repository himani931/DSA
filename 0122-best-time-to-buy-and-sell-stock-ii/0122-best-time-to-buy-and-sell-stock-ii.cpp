class Solution {
public:

    //recursion
    // int solve(int i , int buy , vector<int>& prices) {
    //     if(i == prices.size()) return 0;
        
    //     int profit = 0;

    //     if(buy) {
    //         profit = max((-prices[i] + solve(i + 1 , 0 , prices)) ,( 0 + solve(i + 1 , 1 , prices)));
    //     }

    //     else {
    //         profit = max((prices[i] + solve(i+1 , 1 , prices)) ,( 0 + solve(i + 1 , 0 , prices)));
    //     }
    //     return profit;
    // }

    //top down
     int solve(int i , int buy , vector<int>& prices , vector<vector<int>> &dp) {
        if(i == prices.size()) return 0;

        if(dp[i][buy] != -1) return dp[i][buy];
        
        int profit = 0;

        if(buy) {
            profit = max((-prices[i] + solve(i + 1 , 0 , prices , dp)) ,( 0 + solve(i + 1 , 1 , prices , dp)));
        }

        else {
            profit = max((prices[i] + solve(i+1 , 1 , prices , dp)) ,( 0 + solve(i + 1 , 0 , prices , dp)));
        }
        dp[i][buy] = profit;
        return dp[i][buy];
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<vector<int>> dp(n , vector<int>(2 , -1));
        return solve(0 , 1 , prices , dp);
    }
};