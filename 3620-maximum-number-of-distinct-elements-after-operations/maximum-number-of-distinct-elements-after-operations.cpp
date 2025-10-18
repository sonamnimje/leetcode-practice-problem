class Solution {
public:
    int maxDistinctElements(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        long long last = LLONG_MIN;
        int count = 0;

        for (long long x : nums) {
            long long low = x - k;
            long long high = x + k;

            // pick smallest available value > last
            long long val = max(low, last + 1);

            if (val <= high) {
                count++;
                last = val;
            }
        }
        return count;
    }
};