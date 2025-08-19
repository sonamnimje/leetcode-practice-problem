class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long count = 0;   // total subarrays
        long long streak = 0;  // current consecutive zeros
        for (int n : nums) {
            if (n == 0) {
                streak++;         // extend streak
                count += streak;  // add all subarrays ending here
            } else {
                streak = 0;       // reset on non-zero
            }
        }
        return count;
    }
};