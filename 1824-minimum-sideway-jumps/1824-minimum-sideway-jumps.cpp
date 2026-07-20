class Solution {
public:
//recursion
    // int solve(vector<int>& obstacles , int currlane , int pos){
    //     int n = obstacles.size() - 1;
    //     if(pos == n) return 0;
    //     if(obstacles[pos+1] != currlane) {
    //        return solve(obstacles , currlane , pos+1);
    //     } else{
    //         int ans = INT_MAX;
    //         for(int i = 1 ; i<=3 ; i++) {
    //             if(currlane != i && obstacles[pos] != i){
    //             ans = min(ans , 1 + solve(obstacles , i , pos));
    //             }
    //         }
    //          return ans;

    //     }
    // }

    //top down

     int solve(vector<int>& obstacles , int currlane , int pos , vector<vector<int>> &dp){
        int n = obstacles.size() - 1;
        if(pos == n) return 0;
        if(dp[currlane][pos] != -1) return dp[currlane][pos];
        if(obstacles[pos+1] != currlane) {
           return solve(obstacles , currlane , pos+1 , dp);
        } else{
            int ans = INT_MAX;
            for(int i = 1 ; i<=3 ; i++) {
                if(currlane != i && obstacles[pos] != i){
                ans = min(ans , 1 + solve(obstacles , i , pos , dp));
                }
            }
            dp[currlane][pos] = ans;
             return dp[currlane][pos];

        }
    }

    int minSideJumps(vector<int>& obstacles) {
        vector<vector<int>> dp(4 , vector<int> (obstacles.size() , -1));
        return solve(obstacles , 2 , 0 , dp);
    }
};