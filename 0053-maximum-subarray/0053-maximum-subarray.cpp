class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = 0;
        int maxi = nums[0];
        
        for(int i = 0; i < nums.size(); i++) {
            sum += nums[i];               // include current element
            
            maxi = max(maxi, sum);        // update maximum
            
            if(sum < 0) {                 // reset if sum goes negative
                sum = 0;
            }
        }
        
        return maxi;
    }
};
