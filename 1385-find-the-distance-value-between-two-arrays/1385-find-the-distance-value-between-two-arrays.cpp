class Solution {
public:

    bool isSafe(int n , vector<int> &arr , int d) {
        for(int x : arr) {
            if(abs(x - n) <= d) return false;
        }
        return true;
    }
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) {
        int c =0 ;
        for(int n : arr1) {
            if(isSafe(n , arr2 , d)) c++;
        }
        return c;
    }
};