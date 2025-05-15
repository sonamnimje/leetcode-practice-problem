class Solution {
public:
    int myAtoi(string s) {
        int i = 0, n = s.size();
    
        while (i < n && s[i] == ' ') {
            i++;
        }

        int sign = 1;
        if (i < n && (s[i] == '-' || s[i] == '+')) {
            sign = (s[i] == '-') ? -1 : 1;
            i++;
        }

        long long result = 0;
        bool digits_found = false;
        while (i < n && isdigit(s[i])) {
            digits_found = true;
            int digit = s[i] - '0';
            result = result * 10 + digit;

            if (sign == 1 && result > INT_MAX) {
                return INT_MAX;
            } else if (sign == -1 && -result < INT_MIN) {
                return INT_MIN;
            }

            i++;
        }

        if (!digits_found) return 0;

        result *= sign;

        if (result > INT_MAX) return INT_MAX;
        if (result < INT_MIN) return INT_MIN;

        return static_cast<int>(result);
    }
};