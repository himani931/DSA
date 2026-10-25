class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int ind = -1;

        // Step 1: find the break point
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                ind = i;
                break;
            }
        }

        // Step 2: if no breakpoint, reverse whole array
        if (ind == -1) {
            reverse(nums.begin(), nums.end());
            return;   // 🔑 IMPORTANT
        }

        // Step 3: find element just greater than nums[ind]
        for (int i = n - 1; i > ind; i--) {
            if (nums[i] > nums[ind]) {
                swap(nums[i], nums[ind]);
                break;
            }
        }

        // Step 4: reverse the suffix
        reverse(nums.begin() + ind + 1, nums.end());
    }
};
