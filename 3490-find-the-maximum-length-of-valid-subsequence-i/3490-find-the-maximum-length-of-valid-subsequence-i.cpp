class Solution {
public:
    int maximumLength(vector<int>& nums) {
        int even = 0, odd = 0;
        for (int num : nums) {
            if (num % 2 == 0) even++;
            else odd++;
        }

        int alt = 1;
        int prev = nums[0] % 2;
        for (int i = 1; i < nums.size(); ++i) {
            int curr = nums[i] % 2;
            if (curr != prev) {
                alt++;
                prev = curr;
            }
        }

        return max({even, odd, alt});
    }
};
