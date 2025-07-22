class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        unordered_set<int> seen;
        int start = 0, end = 0, maxSum = 0, currentSum = 0;
        while (end < nums.size()) {
            while (seen.count(nums[end])) {
                seen.erase(nums[start]);
                currentSum -= nums[start];
                start++;
            }
            seen.insert(nums[end]);
            currentSum += nums[end];
            maxSum = max(maxSum, currentSum);
            end++;
        }
        return maxSum;
    }
};