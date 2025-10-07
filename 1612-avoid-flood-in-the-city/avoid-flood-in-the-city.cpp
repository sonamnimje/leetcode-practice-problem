class Solution {
public:
    vector<int> avoidFlood(vector<int>& rains) {
        int n = rains.size();
        vector<int> ans(n, 1); // default: dry lake 1 (arbitrary)
        unordered_map<int, int> full; // lake -> last day it was full
        set<int> dryDays; // indices of dry days

        for (int i = 0; i < n; i++) {
            if (rains[i] == 0) {
                dryDays.insert(i);
            } else {
                int lake = rains[i];
                ans[i] = -1; // rainy day → -1
                
                if (full.count(lake)) {
                    // Need to find a dry day after last time lake was filled
                    auto it = dryDays.lower_bound(full[lake]);
                    if (it == dryDays.end()) {
                        return {}; // no dry day available → flood
                    }
                    ans[*it] = lake; // dry this lake on that day
                    dryDays.erase(it);
                }
                full[lake] = i; // update last rain day for this lake
            }
        }

        return ans;
    }
};