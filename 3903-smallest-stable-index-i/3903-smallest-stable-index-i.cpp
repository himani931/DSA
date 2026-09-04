class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> suffix(n , 0);

        int mini = INT_MAX;

        //suffix minimum
        for(int i = n-1 ; i >= 0 ; i--) {
            mini = min( mini , nums[i]);
            suffix[i] = mini;
        }

        int maxi = 0;

        for(int i = 0 ; i < n ; i++) {
            maxi = max(maxi , nums[i]);
            int score = maxi - suffix[i];
            if(score <= k) return i;
        }
        return -1;
    }
};