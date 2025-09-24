class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        string res;
        if ((numerator < 0) ^ (denominator < 0)) res += "-";
        long n = labs((long)numerator), d = labs((long)denominator);
        res += to_string(n / d);
        long r = n % d;
        if (!r) return res;
        res += ".";
        unordered_map<long, int> seen;
        while (r) {
            if (seen.count(r)) {
                res.insert(seen[r], "(");
                res += ")";
                break;
            }
            seen[r] = res.size();
            r *= 10;
            res += to_string(r / d);
            r %= d;
        }
        return res;
    }
};