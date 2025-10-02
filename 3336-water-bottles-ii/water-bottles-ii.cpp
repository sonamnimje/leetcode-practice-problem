class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int total = numBottles;   // total bottles drunk
        int empty = numBottles;   // empty bottles after drinking

        while (empty >= numExchange) {
            empty -= numExchange; // spend empty bottles for 1 full
            numExchange++;        // exchange cost increases
            total++;              // drink the new bottle
            empty++;              // new bottle becomes empty after drinking
        }

        return total;
    }
};
