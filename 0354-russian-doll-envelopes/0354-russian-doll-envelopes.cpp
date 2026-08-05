class Solution {
public:
    int solve(int n, vector<int> &arr) {
        if (n == 0) return 0;

        vector<int> ans;
        ans.push_back(arr[0]);

        for (int i = 1; i < n; i++) {
            if (arr[i] > ans.back()) {
                ans.push_back(arr[i]);
            } else {
                int index = lower_bound(ans.begin(), ans.end(), arr[i]) - ans.begin();
                ans[index] = arr[i];
            }
        }
        return ans.size();
    }

    int maxEnvelopes(vector<vector<int>>& envelopes) {

        sort(envelopes.begin(), envelopes.end(), [](vector<int> &a, vector<int> &b) {
            if (a[0] == b[0])
                return a[1] > b[1];   // Same width -> height descending
            return a[0] < b[0];       // Width ascending
        });

        vector<int> heights;

        for (auto &e : envelopes)
            heights.push_back(e[1]);

        return solve(heights.size(), heights);
    }
};