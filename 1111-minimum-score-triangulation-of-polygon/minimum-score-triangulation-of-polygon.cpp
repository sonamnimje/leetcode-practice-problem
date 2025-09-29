class Solution {
public:
    int solve(vector<int>& values, int i, int j, vector<vector<int>>& memo) {
        if (j - i < 2) return 0; // no triangle possible
        if (memo[i][j] != -1) return memo[i][j];

        int ans = INT_MAX;
        for (int k = i + 1; k < j; k++) {
            int cost = values[i] * values[j] * values[k]
                     + solve(values, i, k, memo)
                     + solve(values, k, j, memo);
            ans = min(ans, cost);
        }
        return memo[i][j] = ans;
    }

    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        return solve(values, 0, n - 1, memo);
    }
};
