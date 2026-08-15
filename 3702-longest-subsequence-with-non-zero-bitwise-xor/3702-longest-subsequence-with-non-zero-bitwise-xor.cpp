class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int x = 0;
        bool nonZero = false;

        for (int n : nums) {
            x ^= n;
            if (n != 0)
                nonZero = true;
        }

        if (x != 0)
            return nums.size();

        return nonZero ? nums.size() - 1 : 0;
    }
};