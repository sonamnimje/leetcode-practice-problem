class Solution {
public:
    long long minCost(vector<int>& basket1, vector<int>& basket2) {
        map<int, int> count;

        for (int x : basket1) count[x]++;
        for (int x : basket2) count[x]--;

        vector<int> toSwap;

        for (auto& [val, freq] : count) {
            if (freq % 2 != 0) return -1; // Can't make both equal
            for (int i = 0; i < abs(freq) / 2; ++i) {
                toSwap.push_back(val);
            }
        }

        sort(toSwap.begin(), toSwap.end());

        int minValue = min(*min_element(basket1.begin(), basket1.end()), 
                           *min_element(basket2.begin(), basket2.end()));

        long long cost = 0;
        for (int i = 0; i < toSwap.size() / 2; ++i) {
            cost += min(toSwap[i], 2 * minValue);
        }

        return cost;
    }
};
