class Solution {
public:

    //recursion

    // int solve(int n) {
    //     if(n <= 1) return 1;

    //     int ans = 0 ;

    //     for(int i = 1 ;  i<= n ; i++) {
    //         ans += solve(i-1) * solve(n-i);
    //     }
    //     return ans;
    // }

    //top down

    // int solve(int n , vector<int> &dp) {
    //     if(n <= 1) return 1;

    //     if(dp[n] != -1) return dp[n];

    //     int ans = 0 ;

    //     i = root node
    //     for(int i = 1 ;  i<= n ; i++) {
    //         ans += solve(i-1 , dp) * solve(n-i , dp);
    //     }
    //     return dp[n] = ans;
    // }

    //bottom up

    // int solve(int n) {

    //     vector<int> dp(n+1 , 0);

    //     dp[0] = 1;
    //     dp[1] = 1;

    //     int ans = 0 ;

    //     // i = number of nodes
    //     for(int i = 2 ;  i<= n ; i++) {

    //         // j = root node

    //         for(int j = 1 ; j <= i ; j++) {
    //             dp[i] += dp[j-1] * dp[i-j];
    //         }
    //     }
    //     return dp[n];
    // }

    //catalan number

    int cn(int n) {
        long long ans = 1;

        // Cn = (2n)! / (n! * n!)
        // Calculate C(2n, n) iteratively
        for (int i = 1; i <= n; i++) {
            ans = ans * (n + i) / i;
        }

        // Catalan number = C(2n,n) / (n+1)
        return ans / (n + 1);
    }

    int numTrees(int n) {
        // vector<int> dp(n+1 , -1);
        // return solve(n);
        return cn(n);
    }
};