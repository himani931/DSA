class Solution {
public:
    int solve(vector<int>& nums, int cap) {
        int sum=0, count=0;
        for(int n: nums) {
            if(sum+n>cap) {
                count++;
                sum=0;
            }
            sum+=n;
        }
        return count+1;
    }        
    int splitArray(vector<int>& nums, int k) {
        int left=0, right=0;
        for(int n:nums) {
            left=max(left, n);
            right += n;
        }
        while(left<right) {
            int mid = left + (right-left)/2;
            if(solve(nums, mid)>k) {
                left = mid+1;
            }else {
                right = mid;
            }
        }
        return left;
    }
};