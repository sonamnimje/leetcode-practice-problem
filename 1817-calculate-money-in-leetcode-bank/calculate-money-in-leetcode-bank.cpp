class Solution {
public:
    int totalMoney(int n) {
        int weeks = n / 7;
        int days = n % 7;
        int total = weeks * (7 * (1 + weeks)) / 2 + 21 * weeks;
        int start = weeks + 1;
        for (int i = 0; i < days; i++) {
            total += start + i;
        }
        return total;
    }
};