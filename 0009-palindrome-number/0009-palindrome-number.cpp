class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false; // Negative numbers can't be palindromes
        long long dup = x;
        long long revnum = 0;
        while (x > 0) {
            int lastdigit = x % 10;
            revnum = (revnum * 10) + lastdigit;
            x /= 10;
        }
        return revnum == dup;
    }
};
