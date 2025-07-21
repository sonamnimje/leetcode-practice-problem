class Solution {
public:
    string makeFancyString(string s) {
        string result;
        int count = 1; // count of consecutive characters

        for (int i = 1; i < s.length(); ++i) {
            if (s[i] == s[i - 1]) {
                count++;
                if (count < 3) {
                    result += s[i];
                }
            } else {
                count = 1;
                result += s[i];
            }
        }
        return s.empty() ? "" : s[0] + result;
    }
};