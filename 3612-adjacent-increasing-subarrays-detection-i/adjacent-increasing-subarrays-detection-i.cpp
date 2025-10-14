class Solution {
public:
    bool hasIncreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 1, precount = 0, ans = 0;
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++count;
            } else {
                precount = count;
                count = 1;
            }
            ans = max(ans, min(precount, count));
            ans = max(ans, count / 2);
        }
        return ans >= k;
    }
};