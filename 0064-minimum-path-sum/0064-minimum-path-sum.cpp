class Solution {
public:


     // recursion

    // int solve(int i , int j , int m , int n , vector<vector<int>>& Grid) {
//   if(i == m-1 && j == n-1) return Grid[i][j];

//         if(i >= m || j >= n) return 1e9;
        
    //     int right = Grid[i][j] + solve(i , j+1 , m , n , obstacleGrid);
    //     int down = Grid[i][j] + solve(i+1 , j , m , n , obstacleGrid);
        

    //     return  min(right , down);
    // }

  // top down

    int solve(int i , int j , int m , int n  , vector<vector<int>>& Grid , vector<vector<int>> &dp) {
         if(i == m-1 && j == n-1) return Grid[i][j];

        if(i >= m || j >= n) return 1e9;

        if(dp[i][j] != -1) return dp[i][j];

        int right = Grid[i][j] +  solve(i , j+1 , m , n , Grid , dp);
        int down =  Grid[i][j] + solve(i+1 , j , m , n , Grid,  dp);
 
        return dp[i][j] = min(right, down);
        
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<vector<int>> dp ( m , vector<int> (n , -1));

        return solve(0 , 0 , m , n , grid , dp);
    }
};