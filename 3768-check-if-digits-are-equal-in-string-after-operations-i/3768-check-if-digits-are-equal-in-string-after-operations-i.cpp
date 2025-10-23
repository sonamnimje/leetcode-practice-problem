class Solution {
public:
    bool hasSameDigits(string s) {
        while (s.size() > 2) {
            string next = "";
            for (int i = 0; i + 1 < s.size(); ++i) {
                int a = s[i] - '0';
                int b = s[i + 1] - '0';
                next += char(((a + b) % 10) + '0');
            }
            s = next;
        }
        return s[0] == s[1];
    }
};