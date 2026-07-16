class Solution {
public:

//recursion

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

//top down approach

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

//bottom up approach

//  int solve(int n , vector<int>& days, vector<int>& costs) {
//         vector<int> dp(n+1 , INT_MAX);
//         dp[n] = 0;
//         for(int k = n-1 ; k>= 0 ; k--) {

//             int op1 = costs[0] + dp[k+1];

//         int i ;
//         for(i = k ; i< n && days[i] < days[k]+ 7 ; i++);
//         int op2 = costs[1] + dp[i]; 

//          for(i = k ; i< n && days[i] < days[k]+30 ; i++);
//          int op3 = costs[2] + dp[i];

//          dp[k] = min(op1 , min(op2 , op3)); 
//         }
//     return dp[0];
//     }


//space optimization

    int solve(int n , vector<int>& days, vector<int>& costs) {
        int ans = 0;

        queue<pair<int , int >> monthly;
        queue<pair<int , int>> weekly;

        for(int day : days) {
            //remove expired day
            while(!monthly.empty() && monthly.front().first + 30 <= day) {
                monthly.pop();
            }
            while(!weekly.empty() && weekly.front().first + 7 <= day) {
                weekly.pop();
            }
            //add cost for current day

            weekly.push(make_pair(day , ans + costs[1]));
            monthly.push(make_pair(day , ans + costs[2]));

            //update ans
            ans = min(ans+costs[0] , min(weekly.front().second , monthly.front().second));
        }
        return ans;
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n = days.size();
        // vector<int> dp(n+1 , -1);
        return solve(n , days , costs);
        
    }
};