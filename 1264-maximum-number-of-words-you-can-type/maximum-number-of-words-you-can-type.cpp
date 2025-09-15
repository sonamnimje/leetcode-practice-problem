class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        unordered_set<char> broken(brokenLetters.begin(), brokenLetters.end());
        int ans = 0, ok = 1;
        for (char c : text) {
            if (c == ' ') { ans += ok; ok = 1; }
            else if (broken.count(c)) ok = 0;
        }
        return ans + ok;
    }
};