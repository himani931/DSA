class Solution {
public:
    void getSubs(vector<int>& nums, vector<int>& ans, int i, vector<vector<int>>& output) {
        if (i == nums.size()) {
            output.push_back(ans);
            return;
        }

        // Include current element
        ans.push_back(nums[i]);
        getSubs(nums, ans, i + 1, output);

        // Backtrack
        ans.pop_back();

        // Skip duplicates
        int idx = i + 1;
        while (idx < nums.size() && nums[idx] == nums[idx - 1]) {
            idx++;
        }

        // Exclude and jump to next unique element
        getSubs(nums, ans, idx, output);
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> output;
        vector<int> ans;

        getSubs(nums, ans, 0, output); // start from index 0
        return output;
    }
};