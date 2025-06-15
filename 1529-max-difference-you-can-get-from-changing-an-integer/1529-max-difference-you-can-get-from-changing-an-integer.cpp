class Solution {
public:
    int maxDiff(int num) {
        string s = to_string(num);
        string maxStr = s;
        for (char& c : maxStr) {
            if (c != '9') {
                char x = c;
                for (char& ch : maxStr) {
                    if (ch == x) ch = '9';
                }
                break;
            }
        }
        string minStr = s;
        if (s[0] != '1') {
            char x = s[0];
            for (char& ch : minStr) {
                if (ch == x) ch = '1';
            }
        } else {
            for (int i = 1; i < s.size(); ++i) {
                if (s[i] != '0' && s[i] != '1') {
                    char x = s[i];
                    for (int j = 1; j < minStr.size(); ++j) {
                        if (minStr[j] == x) minStr[j] = '0';
                    }
                    break;
                }
            }
        }
        int maxVal = stoi(maxStr);
        int minVal = stoi(minStr);
        return maxVal - minVal;
    }
};