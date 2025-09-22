class Solution {
public:
    int maxFrequencyElements(vector<int>& nums) {
        unordered_map<int,int> freq;
        int maxFreq = 0;
        
        // Count frequencies
        for (int x : nums) {
            freq[x]++;
            maxFreq = max(maxFreq, freq[x]);
        }
        
        // Count total elements with frequency == maxFreq
        int result = 0;
        for (auto &[num, f] : freq) {
            if (f == maxFreq) result += f;
        }
        
        return result;

    }
};