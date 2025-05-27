class Solution {
public:
    int differenceOfSums(int n, int m) {
        int totalSum = n * (n + 1) / 2;
        int count = n / m;
        int divisibleSum = m * count * (count + 1) / 2;
        int nonDivisibleSum = totalSum - divisibleSum;
        return nonDivisibleSum - divisibleSum;
    }
};