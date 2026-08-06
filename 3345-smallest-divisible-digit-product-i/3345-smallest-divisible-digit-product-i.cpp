class Solution {
public:
    int product(int n) {
        int prod = 1;
        while (n) {
            prod *= n % 10;
            n /= 10;
        }
        return prod;
    }
    int smallestNumber(int n, int t) {
        while (product(n) % t != 0) {
            n++;
        }
        return n;
    }
};