class Solution {
public:
    int minMoves(vector<int>& nums) {
        int maxi = 0 ;
        int sum = 0;
        for(int num : nums) {
            maxi = max(maxi , num);
            sum += num;
        }
        return nums.size() * maxi - sum;
    }
};