class Solution {
public:
    // Helper to check if a number is numerically balanced
    bool isBalanced(int num) {
        string s = to_string(num);
        vector<int> freq(10, 0);

        for (char c : s) freq[c - '0']++;
        
        for (char c : s) {
            int d = c - '0';
            if (freq[d] != d) return false;
        }
        return true;
    }

    int nextBeautifulNumber(int n) {
        // Start from n+1 and move upward
        for (int i = n + 1; ; i++) {
            if (isBalanced(i)) return i;
        }
    }
};
