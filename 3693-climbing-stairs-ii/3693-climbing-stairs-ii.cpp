class Solution {
public:
    int climbStairs(int n, vector<int>& costs) {
         costs.insert(costs.begin(), 0);  
        vector<int> dp(n + 3, INT_MAX / 2); 
        dp[n] = costs[n];
        for (int i = n - 1; i >= 0; --i) 
            dp[i] = costs[i] + min({dp[i + 1] + 1, dp[i + 2] + 4, dp[i + 3] + 9});
        return dp[0];
    }
};