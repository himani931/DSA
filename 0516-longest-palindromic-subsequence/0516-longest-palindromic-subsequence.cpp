class Solution {
public:
    
    int solve(string s1, string s2) {
        int n = s1.length();
        int m = s2.length();
        vector<int>curr(m+1 , 0);
        vector<int> next(m+1 ,0);

        for (int i = n - 1; i >= 0; i--) {
            for (int j = m - 1; j >= 0; j--) {
                int ans = 0;
                if (s1[i] == s2[j]) {
                    ans = 1 + next[j + 1];
                } else {
                    ans = max(curr[j + 1],
                              next[j]);
                }
                 curr[j] = ans;
            }
            next = curr;
        }
        return next[0];
    }
    int longestPalindromeSubseq(string s) {
        string rev = s;
        reverse(rev.begin() , rev.end());
        return solve(s , rev);
    }
};