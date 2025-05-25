class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> freq;
        int result = 0;
        bool hasMiddle = false;
        for (const string& word : words) {
            string rev = word;
            reverse(rev.begin(), rev.end());
            if (freq[rev] > 0) {
                result += 4;
                freq[rev]--;
            } else {
                freq[word]++;
            }
        }
        for (auto& [word, count] : freq) {
            if (word[0] == word[1] && count > 0) {
                result += 2;
                break; 
            }
        }
        return result;
    }
};