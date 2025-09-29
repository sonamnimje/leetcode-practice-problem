class Solution {
public:
    int solve(vector<int>& values, int i, int j) {
        // If less than 3 vertices, no triangle possible
        if (j - i < 2) return 0;

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = values[i] * values[j] * values[k]
                     + solve(values, i, k)
                     + solve(values, k, j);
            ans = min(ans, cost);
        }
        return ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        return solve(values, 0, values.size() - 1);
    }
};
