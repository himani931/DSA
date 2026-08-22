class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0 ; 
        int prod = 1;
        for(int i = n ; i > 0 ; i/=10) {
            int r = i % 10;
            sum += r;
            prod *= r;
        }
        return n % (sum + prod) == 0;
    }
};