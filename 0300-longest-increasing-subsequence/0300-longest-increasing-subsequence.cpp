class Solution {
public:
    // recursion

    // int solve(int n , vector<int> &a , int curr , int prev) {
    //     if(curr == n) return 0;

    //     //include
    //     int take = 0;
    //     if(prev == -1 || a[curr] > a[prev]){
    //         take = 1 + solve(n , a , curr+1 , curr);
    //     }

    //     //exclude
    //     int notTake = 0 + solve(n , a , curr+1 , prev);

    //     return max(take , notTake);
    // }

    // top down

    // int solve(int n , vector<int> &a , int curr , int prev ,
    // vector<vector<int>> &dp) {
    //     if(curr == n) return 0;

    //     if(dp[curr][prev + 1] != -1) return dp[curr][prev + 1];

    //     //include
    //     int take = 0;
    //     if(prev == -1 || a[curr] > a[prev]){
    //         take = 1 + solve(n , a , curr+1 , curr , dp);
    //     }

    //     //exclude
    //     int notTake = 0 + solve(n , a , curr+1 , prev , dp);

    //     return dp[curr][prev + 1] = max(take , notTake);
    // }

    // bottom up

    int solve(int n, vector<int>& a) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        for (int curr = n - 1; curr >= 0; curr--) {
            for (int prev = curr - 1; prev >= -1; prev--) {
                // include
                int take = 0;
                if (prev == -1 || a[curr] > a[prev]) {
                    take = 1 + dp[curr + 1][curr + 1];
                }

                // exclude
                int notTake = 0 + dp[curr + 1][prev + 1];

                dp[curr][prev + 1] = max(take, notTake);
            }
        }
        return dp[0][0];
    }

    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();

        // vector<vector<int>> dp(n , vector<int>(n+1 , -1));

        return solve(n, nums);
    }
};