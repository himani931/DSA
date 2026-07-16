class Solution {
public:
// int solve(int n , vector<int>& days, vector<int>& costs , int index) {
//         if(index >= n) return 0 ;

//         int op1 = costs[0] + solve(n , days , costs , index+1 );

//         int i ;
//         for(i = index ; i< n && days[i] < days[index]+ 7 ; i++);
//         int op2 = costs[1] + solve( n , days , costs , i ); 

//          for(i = index ; i< n && days[i] < days[index]+30 ; i++);
//          int op3 = costs[2] + solve(n , days , costs , i );

//           return min(op1 , min(op2 , op3)); 
//           
        
//     }


    // int solve(int n , vector<int>& days, vector<int>& costs , int index , vector<int> &dp) {
    //     if(index >= n) return 0 ;

    //     if(dp[index] != -1) return dp[index];

    //     int op1 = costs[0] + solve(n , days , costs , index+1 , dp);

    //     int i ;
    //     for(i = index ; i< n && days[i] < days[index]+ 7 ; i++);
    //     int op2 = costs[1] + solve( n , days , costs , i , dp); 

    //      for(i = index ; i< n && days[i] < days[index]+30 ; i++);
    //      int op3 = costs[2] + solve(n , days , costs , i , dp);

    //      dp[index] = min(op1 , min(op2 , op3)); 
    //      return dp[index];
        
    // }


 int solve(int n , vector<int>& days, vector<int>& costs) {
        vector<int> dp(n+1 , INT_MAX);
        dp[n] = 0;
        for(int k = n-1 ; k>= 0 ; k--) {

            int op1 = costs[0] + dp[k+1];

        int i ;
        for(i = k ; i< n && days[i] < days[k]+ 7 ; i++);
        int op2 = costs[1] + dp[i]; 

         for(i = k ; i< n && days[i] < days[k]+30 ; i++);
         int op3 = costs[2] + dp[i];

         dp[k] = min(op1 , min(op2 , op3)); 
        }
    return dp[0];
    }
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // vector<int> dp(n+1 , -1);
        return solve(n , days , costs);
        
    }
};