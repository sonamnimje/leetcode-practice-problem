class Solution {
public:
    int maxIncreasingSubarrays(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return 0;

        int cnt = 1;      // current increasing run length
        int precnt = 0;   // previous run length
        int ans = 0;

        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i - 1]) {
                ++cnt;
            } else {
                // consider the single-run split possibility before reset
                ans = max(ans, cnt / 2);
                // move current run to previous and start a new run
                precnt = cnt;
                cnt = 1;
            }
            // consider adjacent runs (previous + current) and current-run split
            ans = max(ans, min(precnt, cnt));
            ans = max(ans, cnt / 2);
        }

        // final run: re-check split and adjacent-case with the last run
        ans = max(ans, min(precnt, cnt));
        ans = max(ans, cnt / 2);

        return ans;
    }
};
