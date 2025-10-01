class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int total = numBottles;  // total drunk bottles
        int empty = numBottles;  // empty bottles after drinking

        while (empty >= numExchange) {
            int newBottles = empty / numExchange;    // how many new full bottles we can get
            total += newBottles;                     // drink them
            empty = empty % numExchange + newBottles; // leftover empties + new empties
        }

        return total;
    }
};
