class Solution {
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        sort(potions.begin(), potions.end());
        int m = potions.size();
        vector<int> res;

        for (long long spell : spells) {
            long long minPotion = (success + spell - 1) / spell;  // ceil(success / spell)
            auto it = lower_bound(potions.begin(), potions.end(), minPotion);
            int count = potions.end() - it;  // all potions >= minPotion
            res.push_back(count);
        }

        return res;
    }
};