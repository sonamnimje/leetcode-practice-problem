class Solution {
public:
    int maxFreqSum(string s) {
        vector<int> freq(26, 0);

        // Count frequency of each character
        for (char ch : s) {
            freq[ch - 'a']++;
        }
        auto isVowel = [](char c) {
            return c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u';
        };

        int maxVowel = 0, maxConsonant = 0;

        // Find maximum vowel and consonant frequency
        for (int i = 0; i < 26; i++) {
            if (freq[i] > 0) {
                char ch = 'a' + i;
                if (isVowel(ch)) {
                    maxVowel = max(maxVowel, freq[i]);
                } else {
                    maxConsonant = max(maxConsonant, freq[i]);
                }
            }
        }
        return maxVowel + maxConsonant;
    }
};
