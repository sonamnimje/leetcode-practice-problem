class Solution {
public:
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>()); // sort in descending order
        for (int i = 0; i < nums.size() - 2; i++) {
            if (nums[i+1] + nums[i+2] > nums[i]) {
                return nums[i] + nums[i+1] + nums[i+2]; // largest perimeter found
            }
        }
        return 0;
    }
};