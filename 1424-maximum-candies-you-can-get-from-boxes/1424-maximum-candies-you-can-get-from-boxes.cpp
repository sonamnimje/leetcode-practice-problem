class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> hasBox(n, false), used(n, false), unlocked(n, false);
        queue<int> q;
        int totalCandies = 0;
        for (int box : initialBoxes) {
            hasBox[box] = true;
        }
        bool progress = true;
        while (progress) {
            progress = false;
            for (int i = 0; i < n; ++i) {
                if (hasBox[i] && (status[i] == 1 || unlocked[i]) && !used[i]) {
                    used[i] = true;
                    totalCandies += candies[i];
                    progress = true;
                    for (int key : keys[i]) {
                        unlocked[key] = true;
                    }
                    for (int box : containedBoxes[i]) {
                        hasBox[box] = true;
                    }
                }
            }
        }
        return totalCandies;
    }
};