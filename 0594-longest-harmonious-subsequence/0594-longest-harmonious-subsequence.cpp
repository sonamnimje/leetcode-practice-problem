class Solution {
public:
    int findLHS(vector<int>& nums) {
         unordered_map<int, int> freq;
        for (int num : nums) {
            freq[num]++;
        }

        int maxLength = 0;
        for (auto& [num, count] : freq) {
            if (freq.count(num + 1)) {
                maxLength = max(maxLength, count + freq[num + 1]);
            }
        }

        return maxLength;
    }
};