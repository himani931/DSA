class Solution {
public:
    // Recursion

    // int solve(vector<int> &nums1 , vector<int> &nums2 , int i , bool swapped)
    // {
    //     if(i == nums1.size()) return 0;
    //     int ans = INT_MAX;
    //     int prev1 = nums1[i -1];
    //     int prev2 = nums2[i-1];

    //     if(swapped) {
    //     swap(prev1 , prev2);
    //     }

    //    if(nums1[i] > prev1 && nums2[i] > prev2) {
    //     ans = solve(nums1 , nums2 , i+1 , 0) ;
    //    }

    //    if(nums1[i] > prev2 && nums2[i] > prev1) {
    //     ans = min(ans , 1 + solve(nums1 , nums2 , i+1 , 1));
    //    }
    //    return ans;

    // }

    // top down

    // int solve(vector<int> &nums1 , vector<int> &nums2 , int i , bool swapped
    // , vector<vector<int>> &dp) {
    //     if(i == nums1.size()) return 0;
    //     int ans = INT_MAX;
    //     int prev1 = nums1[i -1];
    //     int prev2 = nums2[i-1];

    //     if(dp[i][swapped] != -1) return dp[i][swapped];

    //     if(swapped) {
    //     swap(prev1 , prev2);
    //     }

    //    if(nums1[i] > prev1 && nums2[i] > prev2) {
    //     ans = solve(nums1 , nums2 , i+1 , 0 , dp) ;
    //    }

    //    if(nums1[i] > prev2 && nums2[i] > prev1) {
    //     ans = min(ans , 1 + solve(nums1 , nums2 , i+1 , 1 , dp));
    //    }
    //    return dp[i][swapped] = ans;
    // }

    // bottom up

    int solve(vector<int>& nums1, vector<int>& nums2) {

        vector<vector<int>> dp(nums1.size()+1, vector<int>(2, 0));

        for (int i = nums1.size() - 1; i >= 1; i--) {
            for (int swapped = 1; swapped >= 0; swapped--) {

                int ans = INT_MAX;
                int prev1 = nums1[i - 1];
                int prev2 = nums2[i - 1];

                if (swapped) {
                    swap(prev1, prev2);
                }

                if (nums1[i] > prev1 && nums2[i] > prev2) {
                    ans = dp[i + 1][0];
                }

                if (nums1[i] > prev2 && nums2[i] > prev1) {
                    ans = min(ans, 1 + dp[i + 1][1]);
                }
                dp[i][swapped] = ans;
            }
        }
        return dp[1][0];
    }

    int minSwap(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.begin(), -1);
        nums2.insert(nums2.begin(), -1);

        // vector<vector<int>> dp(nums1.size() , vector<int>(2 , -1));
        // bool swapped = 0;
        return solve(nums1, nums2);
    }
};