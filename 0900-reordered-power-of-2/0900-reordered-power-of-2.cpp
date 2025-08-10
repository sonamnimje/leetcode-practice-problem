class Solution {
public:
    bool reorderedPowerOf2(int n) {
        string sig = signature(n);
        static unordered_set<string> powers;
        if (powers.empty()) {
            for (int i = 1; i <= 1e9; i <<= 1) {
                powers.insert(signature(i));
            }
        }
        return powers.count(sig);
    }

private:
    string signature(int x) {
        string s = to_string(x);
        sort(s.begin(), s.end());
        return s;
    }
};
